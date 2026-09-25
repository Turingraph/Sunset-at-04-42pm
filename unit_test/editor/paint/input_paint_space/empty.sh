# https://unix.stackexchange.com/questions/88808/most-efficient-method-to-empty-the-contents-of-a-file

for file in *.txt
do
  echo -n > "$file"
done