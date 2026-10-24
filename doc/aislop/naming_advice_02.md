Yes — **I think many experienced C developers would notice some naming inconsistencies in your library, although they wouldn't necessarily consider them a serious flaw.** More importantly, I suspect they'd encounter a few API-design questions that go beyond naming.

I want to distinguish three things:

- **What an experienced developer would immediately notice:** naming patterns that vary, ambiguous terminology, and unfamiliar abstractions.
- **What would frustrate them while using the library:** having to inspect implementations or examples to understand what a function actually does.
- **What would concern them when adopting the library for a larger project:** unclear ownership, error handling, type safety, and the ability to compose operations predictably.

The first category is largely a matter of taste and consistency. The second and third can affect how pleasant and reliable the library is to use.

One caveat: I can assess the naming and API patterns visible in your linked examples, but I haven't performed a comprehensive audit of every header and implementation in both repositories. I'll distinguish concrete observations from potential weaknesses that would need further investigation.

## 1\. Would experienced C developers notice the naming inconsistencies?

I think so. Here are three examples of the kinds of things that would catch their attention.

### A. The same semantic operation has different naming patterns

Your examples contain names such as:

```
set_cells_color(...)
color_cells_gradient(...)
scale_fdf_table(...)
mix_hadamard_fdf_table(...)
```

An experienced developer might wonder why these functions use different word orders and grammatical structures.

For example, consider:

```
color_cells_gradient(...)
set_cells_color(...)
```

The first starts with an operation that describes a color transformation. The second starts with a generic setter.

That's not necessarily wrong: the functions may perform fundamentally different operations. But the distinction isn't immediately obvious from their names.

A developer might ask:

- Does `set_cells_color()` assign one color to every cell?
- Does `color_cells_gradient()` derive each cell's color from its numerical value?
- Does `set_cells_color()` overwrite colors that were previously computed by `color_cells_gradient()`?
- Is there a general `color_cells()` operation that both functions should use?

The problem isn't that the names are grammatically different. It's that the API doesn't immediately communicate the relationship between the operations.

A more discoverable family might be:

```
surface_set_color(...)
surface_colorize(...)
surface_colorize_gradient(...)
```

This isn't necessarily the exact naming scheme I'd choose for your library. The important thing is that the distinctions become predictable.

**What an experienced developer would likely think:** "I can probably figure this out, but I need to read the documentation or implementation to understand the intended division of responsibility."

That's a relatively minor weakness, but it becomes more noticeable as the number of functions increases.

### B. `scale` appears to cover several different concepts

Your examples use names such as:

```
scale_dim_fdf_table(...)
scale_fdf_table(...)
relu_fdf_table(...)
positive_fdf_table(...)
```

This is potentially more confusing.

In graphics and mathematics, _scale_ has an established meaning: applying a factor to values, coordinates, or dimensions.

For example:

```
scale_vector(...)
matrix_scale(...)
transform_scale(...)
```

These names suggest recognizable mathematical operations.

But consider:

```
relu_fdf_table(...)
```

ReLU is a nonlinear function:

$$
f(x)=\max(0,x)
$$

It is not ordinarily considered a scaling operation.

Likewise, `scale_dim_fdf_table()` sounds as though it might scale dimensions geometrically, resize a data structure, or change the resolution of a grid.

Those are different operations.

An experienced developer might therefore question whether `scale` is being used as a general-purpose verb meaning "modify something numerically."

If so, the name is doing too little work.

I'd prefer names that distinguish the operations:

```
surface_resize(...)
surface_scale(...)
surface_apply_relu(...)
surface_clamp_min(...)
```

The last name is appropriate only if the implementation actually clamps values to a lower bound.

The key issue is **semantic overloading**: one verb is being used for operations that don't necessarily share the same meaning.

This is more consequential than inconsistent word order because it makes the API harder to predict.

### C. The lifecycle vocabulary isn't immediately self-explanatory

Your examples use:

```
create_fdf_table(...)
create_fdf_proj2d(...)
destroy_fdf_table(...)
destroy_fdf_proj2d(...)
```

These names are perfectly understandable in isolation. Many C developers use `init`, `free`, and similar verbs regularly.

However, they raise a question about the library's resource-management model.

Consider:

```
t_fdf_table table = create_fdf_table(300, 300, false);
t_fdf output = create_fdf_proj2d(&table, proj2d_isometric, 0.6);
```

A developer might wonder:

- Do these functions allocate memory internally?
- Does `t_fdf` borrow the table's data or own a copy?
- Can the table be freed before the renderer?
- Can either struct be copied by value?
- What happens if initialization fails?

The names alone don't answer these questions.

An experienced C developer might not consider `init_*` a naming error at all. They might instead consider the ownership contract the more important issue.

That's an important distinction: **a naming inconsistency can be mildly inconvenient, whereas an unclear ownership contract can cause real bugs.**

---

## 2\. What weaknesses would developers experience as users?

This is where I think the more interesting problems lie.

Imagine that an experienced C developer discovers your repository, likes the graphics, and decides to use the library in a personal project.

They aren't evaluating it as its author. They don't know why you chose particular abstractions or how you intended them to be used. They only have the public API, documentation, and examples.

Here are the weaknesses I'd investigate, roughly in order of how much they could affect the user experience.

### 1\. Discoverability: "How am I supposed to find the function I need?"

This is probably the most immediate usability issue.

Suppose a developer wants to apply a transformation to a surface.

They encounter:

```
scale_fdf_table(...)
relu_fdf_table(...)
positive_fdf_table(...)
mix_hadamard_fdf_table(...)
```

They might reasonably ask:

- Where are all the numerical transformations documented?
- Is there a consistent family of operations?
- Should I search for `scale`, `transform`, `apply`, or `table`?
- Are there similar functions whose names I haven't discovered yet?

In C, there is no built-in namespace or method discovery mechanism comparable to those in some other languages. Naming conventions, headers, documentation, and autocomplete do much of that work.

For example, consider these two possible APIs.

**API A:**

```
scale_fdf_table(...);
relu_fdf_table(...);
mix_hadamard_fdf_table(...);
apply_convolution_fdf(...);
```

**API B:**

```
surface_scale(...);
surface_apply_relu(...);
surface_hadamard_product(...);
surface_convolve(...);
```

API A isn't necessarily harder to understand function by function. But API B makes it easier to discover related operations because the shared prefix establishes a recognizable family.

An experienced developer can search for `surface_` and explore the available operations.

**The user experience problem:** users must learn the author's historical naming decisions instead of being able to infer the API's structure.

This matters even more if you eventually have dozens or hundreds of public functions.

### 2\. Predictability: "I understand one function, but can I guess the next one?"

This is closely related to discoverability, but it concerns how much a developer can infer from existing knowledge.

Suppose a developer learns that:

```
color_cells_gradient(...)
```

applies a gradient to a collection of cells.

They might expect related operations to be named:

```
color_cells_solid(...);
color_cells_by_height(...);
color_cells_by_normal(...);
```

Instead, imagine that the library uses:

```
set_cells_color(...);
paint_space(...);
surface_colorize_height(...);
```

Each name could be reasonable in isolation. Collectively, however, they make the naming system difficult to predict.

An experienced developer doesn't necessarily expect every function to share a prefix. They expect related concepts to share a recognizable vocabulary.

This has a practical consequence: **every exception increases the amount of API-specific knowledge users must memorize.**

A small library can tolerate many exceptions. A larger one cannot do so as comfortably.

### 3\. Ambiguous contracts: "What exactly does this function promise?"

This is potentially the most serious issue, although it requires examining the implementations and documentation to establish whether it actually affects your library.

Consider:

```
scale_dim_fdf_table(&table, 3, 3);
```

There are several plausible interpretations:

1. Resize the grid to three times its original width and height.
2. Change the dimensions to exactly three units.
3. Scale the coordinates by three.
4. Change a parameter used when projecting the grid.

The function's name doesn't tell us which interpretation is correct.

A more explicit name might be:

```
surface_resize(&surface, new_width, new_height);
```

or:

```
surface_scale_coordinates(&surface, scale_x, scale_y);
```

The right choice depends on the actual behavior.

This illustrates a broader principle: **a good API name communicates both the operation and its relevant scope.**

The name alone doesn't have to explain every detail. That's what documentation is for. But it should give users a reliable starting point.

I would particularly examine functions whose names combine generic verbs with mathematical or structural terms, such as `scale`, `paint`, `set`, and `init`.

These are not bad words. They simply need clear, consistent meanings within your library.

### 4\. Poor composability: "Can I combine operations without knowing their implementation?"

This is a more subtle concern.

Your examples demonstrate operations being chained together to create interesting results. That's a strength of the project: the library is being used as a medium for mathematical experimentation and artistic expression.

However, a user-friendly graphics API should make it clear which operations:

- Modify an existing object.
- Return a new object.
- Consume another object.
- Borrow data temporarily.
- Operate on a particular channel.
- Preserve or overwrite existing colors.

Consider:

```
mix_hadamard_fdf_table(&table, &table_base, HEIGHT);
scale_fdf_table(&table, 1.0 / 120.0, HEIGHT);
color_cells_gradient(&table, gradient, true);
```

From the call sites alone, I would want to establish the following:

- Does the Hadamard operation overwrite `table`?
- Is `table_base` left unchanged?
- Does scaling affect only the height channel?
- Does colorization overwrite existing color information?
- Does the final Boolean parameter control interpolation, normalization, or something else?

These questions are not proof that the API is defective. They identify information that an unfamiliar user needs.

If the answers are documented consistently, the API might be perfectly usable despite the naming irregularities.

If the answers can only be discovered by reading the implementation, composability becomes more difficult.

One way to improve this is to make the mutation model explicit in the documentation:

```
/*
 * Multiplies corresponding channel values.
 * Modifies dst in place.
 * Does not modify src.
 * Returns false if the dimensions are incompatible.
 */
bool surface_hadamard_product(
    t_surface *dst,
    const t_surface *src,
    t_surface_channel channel
);
```

The signature and documentation above are illustrative; they aren't a claim about your current implementation.

Notice that the function name, argument types, and documentation all contribute to the contract.

That is the standard I'd aim for.

### 5\. Inconsistent abstraction boundaries: "Is this a general-purpose library or a collection of rendering utilities?"

Your repositories contain a mixture of mathematical operations, data manipulation, color mapping, projection, and rendering.

That breadth is interesting, but it creates a design question: which concepts belong to the reusable core, and which are specific to a particular rendering pipeline or artwork?

For example:

```
proj2d_isometric(...)
proj2d_cabinet(...)
```

These names suggest a clear projection abstraction.

By contrast:

```
init_suisei()
init_caramel_pain()
init_white_noise()
```

These appear to describe artistic presets or effects.

Both categories can coexist in the same project. The problem arises if users cannot tell where the general-purpose API ends and the application-specific conveniences begin.

A developer might want to use your convolution or projection routines without adopting the rest of the FDF-oriented data model.

If those operations are tightly coupled to your existing structures, the developer might have to learn more of the library than they expected.

I would not automatically split the library into separate modules or projects. First, I'd establish the conceptual boundaries.

For example:

| Concept | Appropriate responsibility |
| --- | --- |
| Surface or grid | Store and access numerical data |
| Mathematical operations | Transform numerical values |
| Color mapping | Convert values into colors |
| Projection | Map coordinates into projected space |
| Renderer | Produce graphical output |
| Artistic presets | Provide reusable, named configurations |

These boundaries can exist at the level of headers and naming conventions without requiring a complicated architecture.

The user benefit is that someone interested in one part of the library can understand and use it without having to understand every other part.

### 6\. Excessively specific names can make the API harder to extend

This is the opposite problem from ambiguity.

Sometimes a name includes so much implementation or domain detail that it becomes cumbersome or restrictive.

For example:

```
scale_fdf_table(...)
```

If this function multiplies the values of a channel by a scalar, then the word `multiplication` may be unnecessary. Multiplication is the mechanism; scaling is the operation.

A simpler name might be:

```
surface_scale(...)
```

However, this name is only appropriate if the operation has a sufficiently clear and conventional meaning.

Suppose you later want to support:

- Scaling all numerical values.
- Scaling a specific channel.
- Scaling geometric coordinates.
- Scaling the output resolution.

A single `surface_scale()` function might become ambiguous again.

In that case, more specific names could be better:

```
surface_scale_values(...);
surface_scale_coordinates(...);
surface_resize(...);
```

The objective isn't to make every name short. It's to use the minimum specificity necessary to distinguish the operation from related operations.

This is where experienced developers often disagree about API naming. Some prefer concise names; others prefer explicit names. Both can produce good APIs.

The deciding factor should be whether the name communicates the intended contract clearly.

---

## 3\. What would experienced developers _not_ necessarily criticize?

I think this distinction is important because it is easy to become overly critical of your own code when you start examining API design.

Some features of your naming style are reasonable and worth preserving.

### Mathematical names such as `mix_hadamard_fdf_table`

Although its word order differs from some of your other functions, the name identifies the mathematical operation and its data domain.

You could standardize the name to:

```
surface_hadamard_product(...)
```

But the current name isn't intrinsically bad.

If your users are familiar with Hadamard products, the mathematical term is informative. I wouldn't replace it with a generic name such as `combine_tables()` merely to achieve superficial consistency.

### Projection names such as `proj2d_isometric`

These names communicate recognizable concepts.

You might eventually adopt a more uniform API such as:

```
proj2d_isometric(...)
proj2d_cabinet(...)
proj2d_orthographic(...)
```

But if the existing names already follow that pattern, there's little reason to change them.

Consistency isn't an end in itself. It is a way to make the API easier to understand.

### Artistic names such as `init_suisei`

Your project is not merely a conventional graphics library. Its examples have artistic identities.

Names associated with particular artworks, palettes, or effects can make the examples more expressive and memorable.

I would preserve that creativity while keeping the general-purpose operations predictable.

### The use of C-style function names

Your use of functions, structs, and explicit resource-management operations is entirely natural for C.

You don't need to imitate C++ naming conventions or adopt an object-oriented interface just because the API is becoming more sophisticated.

In particular, I wouldn't introduce elaborate abstractions merely to make the library look more professional.

A small, coherent C API is often better than a large framework with unnecessary layers.

---

## 4\. How serious are these weaknesses?

Here's my assessment, with an important qualification: this is a qualitative evaluation of the visible API patterns, not a measured assessment from user testing or a comprehensive source audit.

| Potential weakness | Likely impact on users | Priority |
| --- | --- | --- |
| Inconsistent word order | Mild friction when reading and exploring the API | Low |
| Inconsistent vocabulary for related operations | Makes functions harder to discover and predict | Medium |
| Ambiguous operation names | Users may need to inspect implementations or documentation | Medium to high |
| Unclear mutation and ownership rules | Can cause incorrect assumptions and resource-management bugs | High |
| Inconsistent error-handling conventions | Can make failures difficult to detect and recover from | High |
| Unclear boundaries between general-purpose operations and application-specific features | Makes reuse and extension more difficult | Medium |
| Lack of documentation for mathematical semantics and parameters | Makes the library harder to adopt without studying its source | Medium to high |

The last four points need verification against your actual headers and implementations. I'm not claiming that your library necessarily has defective ownership or error handling; those are areas I'd investigate before drawing a firm conclusion.

The most important distinction is this:

**Inconsistent naming makes an API harder to learn. Inconsistent contracts make an API harder to use correctly.**

The former is what you initially noticed. The latter is what I'd investigate next.

---

## 5\. How would I evaluate your library if I were considering using it?

I'd approach it as an unfamiliar user and attempt five tasks.

### Test 1: Discover a capability

Can I find the operation I need by reading the public headers and using autocomplete, without searching through implementation files?

For example, if I want to apply a convolution, can I find the relevant function quickly?

### Test 2: Predict the behavior

After reading the function's name, signature, and documentation, can I understand what it does and what it modifies?

I shouldn't need to trace five other functions to determine whether an operation changes the input in place.

### Test 3: Handle failure

If a grid has invalid dimensions or two inputs are incompatible, how does the library report the error?

Does it return a status, produce an invalid object, terminate the program, or use some other mechanism?

The behavior should be documented and reasonably consistent.

### Test 4: Manage resources

Can I determine who owns the memory associated with a surface or rendering object?

Can I safely destroy objects in the correct order?

Can I copy the structs, or would doing so create double-free bugs?

These are particularly important questions in C.

### Test 5: Combine operations

Can I combine mathematical transformations, color mapping, and rendering without encountering surprising side effects?

If I perform the same operations in a different order, are the consequences understandable from the API contracts?

Passing these five tests would tell me much more about the library's usability than checking whether all function names follow the same grammatical pattern.

---

## 6\. My advice: conduct a small API usability audit

Rather than immediately renaming everything, I'd take a small, representative portion of your API and evaluate it systematically.

Choose perhaps 15–20 public functions covering:

- Construction and destruction.
- Numerical transformations.
- Color mapping.
- Projection.
- Rendering.

For each function, write down:

1. What does its name suggest?
2. What does it actually do?
3. What state does it modify?
4. Who owns its inputs and outputs?
5. How does it report failure?
6. Can its name be predicted from related functions?

Then look for discrepancies.

For example, if two functions perform similar transformations but differ in whether they modify the input or return a new object, their names or signatures should help distinguish them.

Conversely, if two functions perform the same kind of operation but use different names solely because they were written at different times, they are good candidates for standardization.

I'd also ask someone unfamiliar with the library to complete a simple task using only the public headers and documentation. Observe where they hesitate or make incorrect assumptions.

That would give you evidence about the actual user experience rather than relying entirely on stylistic judgments.

## My final assessment

I think your intuition is reasonable: **an experienced C developer would likely notice the inconsistent vocabulary, but the more significant question is whether those inconsistencies make the API difficult to discover, understand, or use correctly.**

I wouldn't characterize the project as having a fundamentally bad API based on the examples. The operations are often recognizable, and the code demonstrates a useful range of mathematical and artistic applications.

The main opportunity is to make the API more _predictable_.

If I were prioritizing improvements, I'd focus on these three:

1. **Semantic consistency:** Give related operations a common vocabulary and distinguish genuinely different operations.
2. **Contract clarity:** Make mutation, ownership, error handling, and parameter meanings explicit.
3. **Discoverability:** Organize public functions into recognizable families so users can find related capabilities without memorizing the entire API.

I would treat word order and naming style as supporting details rather than the main objective.

Ultimately, the test I'd use is this:

> If a developer understands five functions in your library, how many of the next five should they be able to understand without reading their implementations?

The closer you get to the answer being _most of them_, the more coherent your API will feel.

And that's a more useful goal than simply making all the function names look uniform.