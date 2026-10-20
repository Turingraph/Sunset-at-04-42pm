My first piece of advice is: **don't try to make every API name look consistent in isolation. Instead, make the naming system consistent enough that you can predict an API's name before looking it up.**

For a graphics-oriented C codebase like yours, I'd aim for a small vocabulary, a clear distinction between public and private APIs, and names that reflect the mathematical or graphical operation being performed.

There's also an important distinction between two kinds of consistency:

- **Syntactic consistency:** Are functions, types, macros, and variables named according to predictable rules?
- **Semantic consistency:** Do the names communicate the same concepts in the same way across different parts of the library?

The second is more important. A codebase can use perfectly consistent `snake_case` and still have an arbitrary API if one function uses `draw`, another uses `render`, and a third uses `paint` for essentially the same operation.

I would approach your repositories as a small graphics framework that happens to have several artistic and mathematical applications, rather than as a collection of unrelated programs.

I'll explain how I'd develop that naming system, including some concrete conventions for C and the kinds of graphics code represented by your examples.

## 1\. What stands out in your current API

I looked at the main repository's README and the three C examples you linked. Your project is more than a simple wireframe renderer: it combines a data representation for FDF-like surfaces, mathematical transformations, color mapping, convolution, projection, and rendering. The README also demonstrates that you intend to use these capabilities for artistic applications beyond the original FDF assignment. 【turn1view0】

That matters because I wouldn't design your naming conventions around a conventional graphics renderer alone. Your API needs to express both **mathematical transformations and artistic operations**.

The main README provides a useful cross-section of the API:

```
table = create_fdf_table(100, 100, true);
setcells_pythagorus_length(&table);
set_cells_color(&table_base, 30, HEIGHT, is_oddlength_cube);
fdf_table_hadamard(&table, &table_base, HEIGHT);
scale_relu_fdf(&table, 201, 2000, 0);

color_cells_gradient(&table, init_deep_sea(), true);
scale_multiplication_fdf(&table, 1.0 / 120.0, HEIGHT);

output = create_fdf_proj2d(&table, proj2d_isometric, 0.6);
view_fdf(&output, style);

destroy_fdf_table(&table);
destroy_fdf_proj2d(&output);
```

Source: [Sunset-at-04-42pm README](<https://github.com/Turingraph/Sunset-at-04-42pm>). 【turn1view0】

I see several naming patterns here that are individually understandable but collectively suggest that the API has evolved feature by feature rather than from a single naming vocabulary.

### A. Multiple ways of expressing the same kind of operation

Consider these names:

- `setcells_pythagorus_length`
- `set_cells_color`
- `color_cells_gradient`
- `scale_relu_fdf`
- `scale_multiplication_fdf`
- `fdf_table_hadamard`

Some use `set`, some use `color`, and others use `scale` or a mathematical term. Their word order also varies.

That isn't necessarily a problem with any individual function. The problem is that users have to learn several naming patterns.

For example, if I already know `color_cells_gradient()`, which function should I look for when I want to color cells according to their height?

Would it be:

```
color_cells_height(...);
set_cells_height_color(...);
color_cells_by_height(...);
```

All three are plausible. A well-designed API should make the intended pattern obvious.

### B. Different abstraction levels are mixed together

Consider:

```
fdf_table_hadamard(...)
scale_relu_fdf(...)
scale_multiplication_fdf(...)
```

The Hadamard product is a mathematical operation. ReLU is a nonlinear activation function. Multiplication is an arithmetic operation.

These operations may all be meaningful for your data structure, but they don't necessarily belong to the same semantic category.

For example, `scale_multiplication_fdf()` sounds like multiplication is a particular kind of scaling, while `fdf_table_hadamard()` puts the data structure before the mathematical operation.

I'd choose a consistent naming strategy based on what each operation actually does.

### C. Initialization, construction, transformation, and rendering need distinct vocabularies

Your examples use names such as:

```
create_fdf_table(...)
create_fdf_proj2d(...)
view_fdf(...)
destroy_fdf_table(...)
destroy_fdf_proj2d(...)
```

These are recognizable, but they raise a design question: what exactly distinguishes _initializing_ an object from _creating_ one, and what distinguishes _viewing_ an object from _rendering_ it?

The answer should come from the semantics, not personal preference.

For instance:

- `create` means constructing a new object, usually with allocated resources.
- `init` means initializing an existing object or preparing its state.
- `transform` means changing geometric or numerical properties.
- `render` means producing a visual output.
- `destroy` means releasing the object's resources and ending its lifetime.

These distinctions become particularly valuable as the library grows.

The guiding principle is simple: **one concept, one preferred word**. This is also consistent with established API design guidance that emphasizes simple, intuitive, and consistent terminology. 【turn0search0】【turn0search4】

---

## 2\. My recommended naming convention for your C library

I'd use the following rules as a starting point.

| Element | Recommended convention | Example |
| --- | --- | --- |
| Public functions | `snake_case` | `surface_create()` |
| Public types | `PascalCase` or your existing `t_` convention | `Surface` or `t_surface` |
| Enumerators | `SCREAMING_SNAKE_CASE` | `proj2d_isOMETRIC` |
| Macros | `SCREAMING_SNAKE_CASE` | `SURFACE_MAX_DIMENSION` |
| Private functions | `static` plus `snake_case` | `static map_height_to_color()` |
| Local variables | `snake_case` | `surface_width` |
| Boolean predicates | `is_`, `has_`, or `can_` | `surface_is_empty()` |

For a library that already uses `t_fdf_table`, `t_fdf`, and related names, I wouldn't immediately discard the existing type convention. Changing every type name just to satisfy a stylistic preference would create unnecessary churn.

Instead, I'd establish a consistent public naming scheme for new APIs and gradually migrate the old ones.

### 2.1. Choose one word order

For public functions, I'd generally use:

```
subject_operation(...)
```

when the subject is the main object being manipulated.

For example:

```
surface_create(...)
surface_destroy(...)
surface_transform(...)
surface_render(...)
```

However, this isn't a rule that every function must follow regardless of meaning.

If a function describes a mathematical operation, the operation itself can be the most useful first word:

```
matrix_multiply(...)
vector_normalize(...)
surface_project(...)
color_interpolate(...)
```

The important point is that you establish a small number of predictable patterns and apply them consistently.

I'd avoid mixing these forms for equivalent operations:

```
color_cells_gradient(...);
set_cells_color(...);
gradient_color_cells(...);
```

Pick one vocabulary and one grammatical pattern.

### 2.2. Avoid repeating the type name unnecessarily

Suppose you have:

```
fdf_table_hadamard(...)
scale_multiplication_fdf(...)
```

If the operation belongs to the surface or table module, you may not need to append `_fdf` to every function.

For example:

```
surface_hadamard_product(...)
surface_scale(...)
```

Alternatively, if your library exposes several data types with overlapping operations, explicit prefixes can help:

```
surface_scale(...)
matrix_scale(...)
scale_vector(...)
```

Here, the prefix provides meaningful information by distinguishing the subject.

The rule I'd use is:

**Include the type or module in a function name when it resolves ambiguity, not merely because the function happens to operate on that type.**

### 2.3. Make public names discoverable

Your library's public API should be easy to explore using autocomplete and code search.

A developer should be able to type:

```
surface_
```

and discover the major surface operations.

Likewise:

```
color_
projection_
matrix_
renderer_
```

could expose related groups of functionality.

In C, these prefixes serve as lightweight namespaces. This is particularly useful when the library has no language-level namespace mechanism.

If the project later exposes a stable public API, you could use a library-wide prefix for exported symbols while keeping shorter names inside implementation files.

---

## 3\. Establish a canonical vocabulary for operations

This is the change I'd prioritize over any particular capitalization or word-order rule.

I'd write a short glossary defining the preferred verb for each kind of operation.

| Concept | Preferred word | Intended meaning |
| --- | --- | --- |
| Allocate and construct | `create` | Produce a new object |
| Initialize existing storage | `init` | Establish initial state |
| Release resources | `destroy` | End an object's lifetime |
| Read external data | `load` | Read and interpret data from a source |
| Write external data | `save` | Persist data |
| Change numerical values | `transform` | Apply a mathematical transformation |
| Change geometric dimensions | `resize` | Change dimensions or resolution |
| Change a numerical factor | `scale` | Multiply dimensions or values by a factor |
| Apply a matrix operation | `multiply` | Perform multiplication |
| Map values to colors | `colorize` | Assign colors based on data |
| Draw graphical primitives | `draw` | Produce specific graphical elements |
| Produce a visual result | `render` | Convert a scene or representation into an image |
| Display a result | `present` | Show a rendered result to the user |
| Apply a neighborhood filter | `convolve` | Perform convolution |
| Calculate a value | `compute` | Calculate a derived result |
| Change an object's configuration | `set` | Assign a particular property |
| Test a condition | `is_`, `has_`, `can_` | Return a Boolean result |

These are defaults, not commandments. For example, `scale` is already a well-established mathematical verb, so there is no need to replace it with `transform` everywhere.

The purpose is to prevent synonyms from accumulating without a reason.

### 3.1. Resolve the `view`, `render`, and `draw` distinction

This is particularly relevant to your graphics library.

I would define these terms as follows:

- **`draw`**: Draw an individual primitive, such as a line, circle, or polygon.
- **`render`**: Generate the visual representation of an object or scene.
- **`present`**: Display the completed result in a window.
- **`view`**: Reserve this for an actual view abstraction, such as a camera or viewport, if your architecture has one.

Under this scheme, your current:

```
view_fdf(&output, style, background_color);
```

might become:

```
fdf_render(&output, &style);
```

if it renders the FDF representation into a window or rendering target.

If it both renders and displays the result, I'd consider separating those responsibilities:

```
renderer_render(&renderer, &scene);
window_present(&window, &renderer);
```

These names describe a possible architecture, not a claim that your current implementation has those separate stages. You should only split the functions if the underlying responsibilities genuinely differ.

Why bother?

Imagine that you eventually support rendering to a window, exporting an image, and writing a Blender-compatible file. A single `view_*` vocabulary won't describe those operations particularly well.

A clear distinction between rendering, displaying, and exporting gives you room to extend the library without continually inventing new terminology.

### 3.2. Resolve the `scale` naming family

Your code already contains:

```
scale_multiplication_fdf(...)
scale_dimension_fdf(...)
scale_relu_fdf(...)
scale_positive_fdf(...)
```

These names are not all describing the same operation.

Based on the names and usage in your examples, I'd investigate them as follows:

| Existing name | Possible replacement | Reason |
| --- | --- | --- |
| `scale_multiplication_fdf` | `surface_scale_values` or `surface_multiply_channel` | Clarify whether it scales an entire surface or multiplies a selected channel |
| `scale_dimension_fdf` | `surface_resize` | Appropriate if it changes the surface's dimensions |
| `scale_relu_fdf` | `surface_apply_relu` | Makes the nonlinear operation explicit |
| `scale_positive_fdf` | `surface_clamp_min` or `surface_make_nonnegative` | Depends on whether it clamps values or applies another transformation |

These are deliberately conditional recommendations. The exact names should follow the implementations and contracts, not merely the existing function names.

For example, in your Zutomayo example, you call:

```
table_b = scale_dimension_fdf(&table_a, 3, 3);
scale_multiplication_fdf(&table_b, 3, HEIGHT);
```

The first operation appears to resize the data structure, while the second applies a numerical factor to a channel. Those are distinct concepts, and their names should communicate that distinction. (Source)

I'd also consider whether the name `scale_multiplication_fdf` needs to encode both _scale_ and _multiplication_. If scaling is implemented through multiplication, that implementation detail might not belong in the public name.

Prefer naming the mathematical effect rather than describing how you happened to implement it.

---

## 4\. Separate the mathematical API from the graphics API

Your non-Euclidean example is particularly revealing.

It contains operations such as:

```
paint_space(&table, HEIGHT, cell_metric_max_xy);
fdf_table_hadamard(&table, &table_base, HEIGHT);
color_cells_gradient(&table, init_floor(), true);
scale_multiplication_fdf(&table, 1.0 / 120.0, HEIGHT);
output = create_fdf_proj2d(&table, NULL, 0.6);
view_fdf(&output, style, background_color);
```

The code combines several layers:

1. Mathematical construction of a data representation.
2. Element-wise arithmetic.
3. Color mapping.
4. Numerical scaling.
5. Conversion into a renderable representation.
6. Display.

That is a useful foundation for a graphics framework, but the names could communicate those layers more clearly. (Source)

I'd consider organizing the public API into conceptual modules.

### Layer A: Data structures

Responsible for creating, managing, and accessing the underlying representation.

```
surface_create(...)
surface_destroy(...)
surface_get_cell(...)
surface_set_cell(...)
surface_resize(...)
```

Here, `surface` is an illustrative name for a regular grid of height or other per-cell values. If your data structure is more accurately a table or scalar field, use that term instead.

### Layer B: Mathematics

Responsible for operations on vectors, matrices, grids, and numerical fields.

```
matrix_multiply(...)
surface_hadamard_product(...)
surface_apply_relu(...)
surface_scale(...)
surface_convolve(...)
```

The mathematical vocabulary should remain recognizable to someone familiar with linear algebra, numerical computing, or image processing.

For example, I would retain `hadamard_product` rather than replacing it with a generic name like `combine_tables`. The former identifies a precise mathematical operation; the latter doesn't.

### Layer C: Color and artistic transformations

Responsible for mapping data into an artistic representation.

```
color_gradient_create(...)
surface_colorize(...)
surface_colorize_by_height(...)
surface_colorize_by_channel(...)
```

The distinction between `colorize` and `set_color` is important here.

- `set_color` suggests assigning a particular color.
- `colorize` suggests deriving colors from data or a mapping.

That distinction gives you a natural vocabulary for gradients, channel-based coloring, and other visual effects.

### Layer D: Geometry and projection

Responsible for converting mathematical coordinates into projected coordinates.

```
proj2d_isometric(...)
proj2d_cabinet(...)
proj2d_orthographic(...)
surface_project(...)
```

Your current names, such as `proj2d_isometric` and `proj2d_cabinet`, are already fairly descriptive.

I'd preserve established mathematical terminology wherever possible instead of renaming things just for the sake of uniformity.

### Layer E: Rendering and output

Responsible for converting the representation into something a user can see or save.

```
renderer_create(...)
renderer_render(...)
window_present(...)
image_save(...)
```

These names would make it easier to add different output backends without confusing a mathematical operation with a display operation.

**One important qualification:** these layers are conceptual boundaries, not a demand to create five separate libraries. You can keep the implementation compact while maintaining clear naming boundaries.

---

## 5\. Distinguish public APIs from artistic examples

This is an important point specific to your repositories.

Your `hyperbolic.c`, `editor.c`, and `view_blue_kusama.c` files are applications of the library. They don't all need the same naming conventions as the library itself.

For example, your Suisei example defines these functions:

```
init_white_noise()
init_suisei()
init_caramel_pain()
```

These names make sense in the context of that artwork: they're recognizable as presets associated with the visual effect being created. The code uses them to configure gradients before rendering the final result. (Source)

I wouldn't necessarily rename `init_suisei()` to something generic. The artistic meaning is valuable.

Instead, I'd distinguish **general-purpose operations** from **application-specific presets**.

For example, imagine a revised API:

```
/* General-purpose library API. */

Gradient gradient_create(...);

void surface_colorize(
    Surface *surface,
    const Gradient *gradient
);

/* Application-specific artistic presets. */

Gradient suisei_gradient(void);
Gradient kusama_gradient(void);
Gradient deep_sea_gradient(void);
```

These names are illustrative, but the separation is deliberate.

- `gradient_create()` belongs to the general-purpose library.
- `surface_colorize()` describes a reusable operation.
- `suisei_gradient()` describes a particular artistic preset.

This makes the API more predictable without removing the personality from your examples.

### What about `init_white_noise()`?

I'd examine that name more carefully.

In the examples, the function returns a `t_gradient`, and its name suggests that it initializes white noise. However, the implementation shown in your examples constructs a gradient whose input range is zero and whose two endpoint colors are identical.

That might be a deliberate way of producing a constant color or a particular rendering effect, rather than generating random noise.

If so, a name such as:

```
black_gradient()
```

or:

```
constant_color_gradient(...)
```

might better communicate the behavior, depending on the intended semantics.

I wouldn't rename it solely on the basis of the name, though. I'd first establish what the preset is intended to represent.

The general rule is that **a name should describe the behavior or meaning of an abstraction, not merely its historical origin**.

---

## 6\. Resolve the `init_*` versus `create_*` question

This is one of the most consequential choices for a C API because it affects resource management and ownership.

Your examples currently follow a pattern similar to:

```
t_fdf_table table;

table = create_fdf_table(100, 100, true);

/* Use table. */

destroy_fdf_table(&table);
```

And:

```
t_fdf output;

output = create_fdf_proj2d(&table, proj2d_isometric, 0.6);

/* Use output. */

destroy_fdf_proj2d(&output);
```

These functions return objects by value, and the corresponding cleanup functions release their resources.

Returning a struct by value is perfectly reasonable in C. The question is what the API promises about the returned object and how its ownership works.

I'd consider two possible conventions.

### Option A: Keep the current value-oriented design

If the returned structures own their resources, and copying them is either safe or explicitly restricted by convention, you could use:

```
Surface surface_create(...);
void surface_destroy(Surface *surface);
```

For a library that uses `t_` prefixes:

```
t_surface surface_create(...);
void surface_destroy(t_surface *surface);
```

This is a straightforward naming system.

The important detail is that `create` and `destroy` describe the lifetime of the object, regardless of whether its storage is allocated on the heap.

### Option B: Use explicit initialization and destruction

If callers provide the storage, an alternative is:

```
bool surface_init(
    t_surface *surface,
    size_t width,
    size_t height
);

void surface_destroy(t_surface *surface);
```

The caller might then write:

```
t_surface surface;

if (!surface_init(&surface, 100, 100))
    return (1);

/* Use surface. */

surface_destroy(&surface);
```

Here, `init` is appropriate because the caller already has storage for the object.

In a real implementation, you would also need to define what happens on initialization failure and whether destruction is safe after partial initialization.

### My recommendation

For your existing API, I'd choose `create` for functions that construct new logical objects and `init` for functions that initialize existing objects.

I would not make a blanket change from `init_*` to `create_*` until you've examined ownership, failure handling, and whether returned structs can be copied safely.

**Naming should expose the resource-management model, not obscure it.**

---

## 7\. Establish a policy for mathematical terminology

Your project uses a mixture of mathematical terms and application-specific names. That's not inherently inconsistent; graphics and numerical computing need specialized vocabulary.

The key is to distinguish three categories.

### Category A: Standard mathematical terminology

Examples:

```
matrix_multiply(...)
hadamard_product(...)
vector_normalize(...)
orthographic_projection(...)
```

Preserve these names when they accurately describe standard operations.

For instance, `hadamard_product()` is more informative than `elementwise_combine()` if the operation is indeed the Hadamard product.

### Category B: Domain-specific operations

Examples:

```
surface_project(...)
surface_convolve(...)
surface_colorize(...)
```

These names combine your application's domain with a recognized operation.

They are especially useful when several types can undergo the same operation.

### Category C: Artistic concepts

Examples:

```
deep_sea_gradient()
kusama_pattern()
suisei_palette()
```

These names express artistic intent rather than a universal mathematical operation.

I'd preserve this category because it is part of what makes your project distinctive.

However, I'd avoid mixing artistic names into general-purpose operations unless the artistic concept has become a well-defined reusable abstraction.

For example, a general-purpose color-mapping function should not be called `paint_suisei()` merely because your first use of it was in that artwork.

---

## 8\. A concrete before-and-after example

Let's put these ideas together.

Your existing code in the non-Euclidean example contains this sequence:

```
table_base = create_fdf_table(300, 300, false);

set_cells_color(
    &table_base,
    3,
    HEIGHT,
    is_andmod_x3
);

table = create_fdf_table(300, 300, true);

paint_space(
    &table,
    HEIGHT,
    cell_metric_max_xy
);

fdf_table_hadamard(
    &table,
    &table_base,
    HEIGHT
);

color_cells_gradient(
    &table,
    init_floor(),
    true
);

scale_multiplication_fdf(
    &table,
    1.0 / 120.0,
    HEIGHT
);

output = create_fdf_proj2d(
    &table,
    NULL,
    0.6
);

view_fdf(
    &output,
    style,
    background_color
);
```

Source: hyperbolic.c.

A more coherent API might look like this:

```
t_surface base = surface_create(300, 300, false);
t_surface surface = surface_create(300, 300, true);

/* Populate the base surface with a numerical pattern. */
surface_map_channel(
    &base,
    SURFACE_CHANNEL_HEIGHT,
    3,
    is_andmod_x3
);

/* Construct the main mathematical surface. */
surface_map_channel(
    &surface,
    SURFACE_CHANNEL_HEIGHT,
    0,
    cell_metric_max_xy
);

/* Combine the surfaces using the Hadamard product. */
surface_hadamard_product(
    &surface,
    &base,
    SURFACE_CHANNEL_HEIGHT
);

/* Apply artistic color mappings. */
surface_colorize(&surface, &floor_gradient);
surface_scale(
    &surface,
    1.0 / 120.0,
    SURFACE_CHANNEL_HEIGHT
);

/* Project and render. */
t_fdf output = fdf_create(
    &surface,
    proj2d_cabinet,
    0.6
);

fdf_render(&output, &style);

/* Release resources. */
surface_destroy(&surface);
surface_destroy(&base);
fdf_destroy(&output);
```

This is a **proposed naming sketch, not drop-in replacement code**. Some function signatures differ from your current API, and the exact names depend on the implementation.

In particular, I would verify what `paint_space()` does before replacing it with `surface_map_channel()`. The example assumes that its behavior is equivalent to assigning values to a channel, which may not be true.

Similarly, I would retain `t_fdf_table` instead of introducing `t_surface` if the latter would misrepresent the data structure. The point is the naming pattern, not the specific type name.

Notice the structural improvements:

- Construction consistently uses `create`.
- Destruction consistently uses `destroy`.
- The mathematical operation is named explicitly.
- Color mapping has a recognizable vocabulary.
- Rendering is distinct from construction.
- Channel identifiers have a consistent form.

Most importantly, a reader can infer the general structure of the API without memorizing every function individually.

---

## 9\. What I would change first in your actual repositories

I wouldn't begin by renaming every symbol. Your library already has working examples, and your current names are used throughout the codebase.

I'd make changes in this order.

### Priority 1: Fix ambiguous or misleading names

Start with functions whose names make it difficult to understand what they do.

Candidates for investigation include:

| Existing name | What I'd investigate |
| --- | --- |
| `view_fdf()` | Does it render, display, or both? |
| `create_fdf_proj2d()` | Does it construct a new object or initialize existing storage? |
| `scale_multiplication_fdf()` | Is it scaling values, multiplying a channel, or performing another operation? |
| `scale_dimension_fdf()` | Does it resize the grid or transform geometric dimensions? |
| `paint_space()` | Does it populate a numerical field, generate geometry, or do something else? |
| `setcells_pythagorus_length()` | Does it assign a distance metric to cells? |
| `color_cells_gradient()` | Does it assign colors directly or map values through a gradient? |

These are questions to resolve by reading the implementations, not automatic renaming recommendations.

### Priority 2: Normalize equivalent operations

Search the headers and implementations for functions that perform similar operations but use different verbs.

For example:

```
set_cells_color(...)
color_cells_gradient(...)
paint_space(...)
```

Determine which operations are genuinely distinct and which are simply different interfaces for the same concept.

Then choose a canonical verb for each category.

I'd prioritize the core mathematical and rendering APIs before the application-specific examples.

### Priority 3: Standardize object lifecycles

Make the creation, initialization, and destruction conventions consistent.

For example:

```
surface_create(...)
surface_init(...)
surface_destroy(...)
```

These names should have clearly documented responsibilities.

Avoid retaining both `destroy_fdf_table()` and `destroy_fdf_proj2d()` solely because they were implemented at different times. If they release different kinds of objects, their distinct type names should make that difference clear.

### Priority 4: Improve type and enum naming

Your existing identifiers include:

```
t_fdf_table
t_fdf
t_style_render
D7_HEIGHT
E_LINE
E_RECTANGLE
```

I'd make a deliberate decision about the type-prefix convention and enum conventions.

For example, if you retain the `t_` convention:

```
typedef struct t_surface
{
    /* ... */
} t_surface;
```

You could define enum values as:

```
typedef enum e_surface_channel
{
    SURFACE_CHANNEL_HEIGHT,
    SURFACE_CHANNEL_RED,
    SURFACE_CHANNEL_GREEN,
    SURFACE_CHANNEL_BLUE,
    SURFACE_CHANNEL_ALPHA
} t_surface_channel;
```

This is a possible modernized style, not a requirement to abandon your existing naming system.

The advantage is that a developer can identify a channel constant by its prefix and distinguish it from a type or function.

### Priority 5: Separate public API conventions from local coding conventions

Your library's public symbols should follow a documented convention, while local implementation details can use shorter names when appropriate.

For example:

```
/* Public API. */
t_surface surface_create(size_t width, size_t height);

/* Private implementation detail. */
static bool map_channel_value(...);
```

In C, `static` gives a file-scope function internal linkage. Use it for functions that don't need to be visible to other translation units.

This also reduces the chance of symbol collisions when your library is linked with other software. C libraries commonly use a project-specific prefix for public symbols for this reason. (GROMACS naming conventions)([Proven C Book](<https://rubidus-api.github.io/proven_c_book/en/ch60.html>))

---

## 10\. Don't rename the whole API in one pass

I would create a naming policy first, then migrate incrementally.

A practical process would be:

1. List all public functions declared in your headers.
2. Group them by semantic purpose: data structures, mathematics, color, projection, rendering, and I/O.
3. Record the current name, actual behavior, proposed name, and rationale.
4. Identify duplicated concepts and misleading names.
5. Establish canonical vocabulary for each category.
6. Rename the most important public APIs.
7. Update all examples and tests.
8. Document compatibility changes.

A simple spreadsheet or Markdown table would be sufficient.

For example:

| Current name | Proposed name | Rationale | Status |
| --- | --- | --- | --- |
| `create_fdf_table` | `surface_create` | Align construction terminology | Proposed |
| `destroy_fdf_table` | `surface_destroy` | Align lifecycle terminology | Proposed |
| `scale_dimension_fdf` | `surface_resize` | Clarify dimensional changes | Needs verification |
| `scale_multiplication_fdf` | `surface_scale` | Simplify numerical operation | Needs verification |
| `view_fdf` | `fdf_render` | Clarify rendering responsibility | Needs verification |

I would also distinguish between a purely mechanical rename and a semantic redesign.

A mechanical rename should preserve behavior and can be automated. A semantic redesign may require changing function signatures, ownership rules, or responsibilities and deserves separate commits.

If other programs already depend on the library, you could temporarily preserve the old functions as compatibility wrappers:

```
/* Legacy API. */
t_fdf_table create_fdf_table(size_t width, size_t height, bool flag)
{
    return surface_create(width, height, flag);
}
```

That example assumes compatible types and behavior; the actual wrapper would need to match your existing signatures.

If the project is still evolving and has few external users, a clean break may be simpler. In either case, update the documentation so users know which names are preferred.

---

## 11\. One final recommendation: document the naming philosophy

I would add a short `doc/contribution/naming.md` file, or an equivalent section in your contributor documentation.

It doesn't need to be long.

I'd document five rules:

1. **One concept, one preferred word.** Avoid introducing synonyms for the same operation.
2. **Names describe semantics.** Prefer the operation's meaning over its implementation.
3. **Use predictable word order.** Follow the conventions established for each API category.
4. **Preserve established mathematical terminology.** Don't replace precise mathematical names with vague generic ones.
5. **Keep artistic presets separate from general-purpose operations.** Preserve expressive names when they describe genuine artistic concepts.

I'd add a short glossary defining terms such as `create`, `init`, `destroy`, `transform`, `scale`, `colorize`, `render`, and `present`.

When introducing a new public function, the contributor should be able to answer two questions:

- What existing naming pattern does this function follow?
- What distinguishes this operation from other operations with similar names?

If those questions have clear answers, your API is much less likely to become arbitrary as you add features.

## My overall verdict

I wouldn't say that your API needs a completely new naming style. Much of it is already understandable, and names such as `proj2d_isometric`, `proj2d_cabinet`, and `fdf_table_hadamard` communicate recognizable concepts.

The underlying issue is that **the API doesn't yet appear to have a sufficiently explicit vocabulary for expressing its different kinds of operations**.

If I were maintaining this project, my first three changes would be:

1. Standardize object lifecycle names around `create`/`init`/`destroy`.
2. Establish a canonical vocabulary for numerical transformations, color mapping, and rendering.
3. Separate general-purpose library APIs from artistic presets and example-specific functions.

I'd make those changes before debating whether every function should put its type name first or last.

One last consideration: I would not force the entire API into a single grammatical pattern. `matrix_multiply()`, `surface_resize()`, `gradient_create()`, and `renderer_render()` don't have identical word order, but each can still belong to a coherent system. What matters is that the order follows a small set of understandable rules.

**The goal isn't for every name to look alike. It's for every name to feel like it belongs to the same library.**