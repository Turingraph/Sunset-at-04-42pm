# https://stackoverflow.com/questions/7450818/rename-all-files-in-directory-from-filename-h-to-filename-half

for file in *.fdf
do
  mv "$file" "${file/.fdf/.txt}"
done