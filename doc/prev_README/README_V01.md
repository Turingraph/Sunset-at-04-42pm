# Previous Note

I plan to make fdf42, and I also add the feature that allow user to convert ASCII text (including Figlet output) as fdf42 input files, and display them as prism (with Z buffer) instead of isometric projection that looks like boring chocolate (as I see in original fdf42). The user can choose the origin of x and y on the tables of integers, also paint those prism with complex conformal map as rgba value on each cells, and use Gaussian convolution when they wish to do it and also save it as new fdf42 files. Also I plan to make it utilize mainly OpenGL/GLFW directly. The reason I do this is because I have grapheme color synesthesia, I never use Blender, and I want to show audience what is the color of alphabet and display it as 3D typography for pure artistic reason and as IT job portfolio. 

Another interesting idea is that I can also show the audience about my personal experience with how learning 3rd language and synesthesia experience interact with each other, if I have opportunity to learn 3rd language consistently.

Thing that I didn't do it yet, but I should do before Submission
1.	editor/line/ for draw simple square tiling Islamic art and polygon
2.	graphic/window/ (with only keyboard based UXUI)
3.	user tutorial and README.md
4.	fix some part of coding_examples/ (triangle_pair, triangle_arr, and line)

Thing to do before release First Stable Version (but I should avoid doing it now because I have only 2 weeks to finish this Fdf42 and also finish Push Swap that I didn't begin at all, or else I'm "fired" from 42 Coding School)
1.	input/copy/ (copy/paste some region of the t_table_fdf to another region of t_table_fdf)
2.	input/compress/ (reducing dst->row and/or dst->col)
3.	input/upsidedown/ (and also 90 degree rotation and mirror)
4.	editor/paint/ (normal and uniform statistic based painting)
5.	editor/conformal/
6.	editor/matrix_rgba/ (multiply 4D square matrix with r,g,b, and a)
7.	editor/convolve/ (determanent based filtering and strassen algorithm)
8.	graphic/rasterization/ with z buffer
9.	replace MLX42/minilibX42 as OpenGL and GLFW.

Thing to do "after" the first stable version, to avoid scope creep.
1.	editor/mathart/derivative/ for draw the image according to the local derivative, curl, gradient, and Jacobian determanent of the image.
2.	editor/fractal/ (including Julia, Newton fractal etc.) for drawing/painting Fractal.
3.	mouse based UXUI and throttle
4.	Figlet in other languages and language specialized related features e.g. Thai (my native language and Thai and English are the only language that I can speak and read currently), Myanmar, Khmer, Ainu, Zhuang, Japanese (I plan to learn Japanese as third language because I love anime, Jpop, and I want interesting writing system for this Git repo), Pali, Chinese (my parents and some other in my family tree can speak Chinese but I can't so I wish to learn this language as 4th language), Arabic, Biblaridion's Edun, Kat Mistberg's Unordered language etc.
5.	Content about my personal experience with synesthesia, language, my experience with meditation while observing random thought, my experience with learning 3rd language and how this experience interact with my synesthesia experience and vise versa, written conlang (and neography), etymology, preserving endangered language, Phenomenology, Calligraphy based Tarot cards etc.
6.	Blender/Piskel/Jpg/PDF compatible file
7.	React Typescript user friendly Frontend
8.	Font topology/graphic related analysis

To Do List
1.	Merge graphic/fdf/ as utils/linalg/ and graphic/window/
2.	Build the very simple Fdf (with minimal feature)
3.	.

Nice to do
1.	Prism
2.	graphic/line/
3.	.
