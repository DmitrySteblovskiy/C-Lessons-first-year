echo "Hi everyone, it's your daily dose of Linux!"
sleep 2

mkdir -p tests_scripts

echo "Попробуйте исправить этот скрипт так, чтобы он успешно запускал создаваемый далее скрипт "
echo "и в нём последовательно выводил ваш никнейм, имя хоста, дату и все файлы репозитория без лишнего текста."

sleep 5
echo "Good Luck!"

sleep 1

echo '

username=$(whoami)
echo "Привет, $username, fix this script, please"

' > tests_scripts/my_script.sh

tests_scripts/my_script.sh
