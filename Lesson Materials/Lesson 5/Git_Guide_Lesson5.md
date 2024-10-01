
# Вход в GitHub и Клонирование Репозитория

## Шаг 1: Настройка Консоли

Проверим, что у нас установлен Git:

```sh
git --version
```

Если Git не установлен, установите его с помощью:
```sh
sudo apt update
sudo apt install git
```

## Шаг 2: Настройка Git с вашим пользователем

Настройте ваше имя и email, чтобы GitHub знал, кто делает коммиты:
```sh
git config --global user.name "Ваше Имя"
git config --global user.email "ваш.email@example.com"
```

## Шаг 3: Создание и использование Personal Access Token для HTTPS

### Создание Personal Access Token:

1. Зайдите в ваш аккаунт на GitHub.
2. Перейдите в "Settings" -> "Developer settings" -> "Personal access tokens".
3. Нажмите "Generate new token".
4. Установите нужные разрешения для токена (например, `repo` для доступа к репозиториям).
5. Сохраните токен в безопасное место, так как он будет показан только один раз.

### Использование HTTPS для клонирования:

Склонируйте репозиторий с помощью HTTPS. Во время клонирования вас попросят ввести ваш Personal Access Token в качестве пароля.

```sh
git clone https://github.com/username/repository.git
```

## Шаг 4: Создание SSH ключа и настройка GitHub для SSH

### Создание SSH ключа:

1. Сгенерируйте SSH ключ с вашим email:
```sh
ssh-keygen -t ed25519 -C "ваш.email@example.com"
```

2. Следуйте инструкциям на экране (по умолчанию ключ хранится в `~/.ssh/id_ed25519`).
3. Добавьте SSH ключ в ssh-agent:
```sh
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_ed25519
```

### Добавление SSH ключа в GitHub:

1. Скопируйте содержимое ключа в буфер обмена:
```sh
cat ~/.ssh/id_ed25519.pub
```
2. Войдите в свой GitHub аккаунт.
3. Перейдите в "Settings" -> "SSH and GPG keys".
4. Нажмите "New SSH key", вставьте ваш ключ и нажмите "Add SSH key".

### Использование SSH для клонирования:

Склонируйте репозиторий с помощью SSH:
```sh
git clone git@github.com:username/repository.git
```



## Зачем использовать `git status`?

### Команда `git status`:

Команда `git status` используется для проверки текущего состояния репозитория. Она показывает:
- Измененные файлы, которые были добавлены в индекс (staged).
- Измененные файлы, которые еще не добавлены в индекс (unstaged).
- Немодифицированные файлы.

Пример использования:
```sh
git status
```
Вывод может выглядеть так:
```sh
On branch main
Your branch is up to date with 'origin/main'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
	modified:   file1.txt

Untracked files:
  (use "git add <file>..." to include in what will be committed)
	file2.txt

no changes added to commit (use "git add" and/or "git commit -a")
```

## Как сделать первый коммит в GitHub через консоль Ubuntu

### Шаг 1: Инициализация репозитория

Если это новый проект, инициализируйте новый Git репозиторий:
```sh
git init
```

### Шаг 2: Добавление файлов в индекс

Добавьте файлы в индекс (staging area):
```sh
git add <имя_файла>   # Добавить конкретный файл
git add .             # Добавить все файлы в текущей директории
```

### Шаг 3: Сделать первый коммит

Создайте коммит с сообщением:
```sh
git commit -m "First commit"
```

### Шаг 4: Пуш изменений в удаленный репозиторий

Если ваш локальный репозиторий еще не связан с удаленным, свяжите его:
```sh
git remote add origin https://github.com/username/repository.git
```

Для пуша изменений:
```sh
git push -u origin main
```

## Как пуллить изменения из репозитория

Чтобы получить последние изменения из удаленного репозитория и объединить их с вашим локальным:
```sh
git pull origin main
```

## Как создать новую ветку и переключаться между ветками

### Создание новой ветки:

Чтобы создать новую ветку:
```sh
git branch <имя_ветки>
```

### Переключение на новую ветку:

Чтобы переключиться на новую ветку:
```sh
git checkout <имя_ветки>
```

Или вы можете создать и переключиться на новую ветку в одной команде:
```sh
git checkout -b <имя_ветки>
```

### Просмотр текущих веток:

Чтобы увидеть список всех веток и текущую активную ветку:
```sh
git branch
```
Конечно! Вот подробное руководство по использованию команд Git `git remote add`, `git remote -v`, `git fetch`, `git reset --hard`, и `git rebase`.

```markdown
# Основные Команды Git: Подробное Руководство

## Команда `git remote add`

### Описание:

Команда `git remote add` используется для добавления нового удаленного репозитория, обеспечивая возможность взаимодействия с ним (например, пуш и пул изменений).

### Синтаксис:
```sh
git remote add [slug] [url]
```

### Пример использования:
Добавляем удаленный репозиторий с именем `origin`:
```sh
git remote add origin https://github.com/username/repository.git
```

## Команда `git remote -v`

### Описание:

Команда `git remote -v` выводит список всех удаленных репозиториев, связанных с текущим репозиторием, и показывает их URL для операций fetch и push.

### Синтаксис:
```sh
git remote -v
```

### Пример использования:
```sh
git remote -v
```
Вывод может выглядеть так:
```sh
origin  https://github.com/username/repository.git (fetch)
origin  https://github.com/username/repository.git (push)
```

## Команда `git fetch`

### Описание:

Команда `git fetch` загружает все изменения из удаленного репозитория, но не интегрирует их с локальными изменениями. Это полезно для получения обновлений без изменения текущей рабочей ветки.

### Синтаксис:
```sh
git fetch [repository]
```

### Пример использования:
Получаем все изменения из удаленного репозитория `origin`:
```sh
git fetch origin
```

## Команда `git rebase`

### Описание:

Команда `git rebase` позволяет интегрировать изменения из одной ветки в другую, создавая линейную историю коммитов. Это может быть полезно для очистки истории или упрощения слияния изменений.

### Синтаксис:
```sh
git rebase [branch]
```

### Пример использования:
Переносим изменения из ветки `feature` в текущую ветку:
```sh
git checkout main
git rebase feature
```

## Команда `git reset --hard`

### Описание:

Команда `git reset --hard` бывает иногда удобна и необходима, когда нужен сброс текущего состояния репозитория к определенному коммиту, удаляя все текущие незакоммиченные изменения
### Синтаксис:
```sh
git reset --hard [commit]
```

### Пример использования:
Сбрасываемся к последнему коммиту в текущей ветке:
```sh
git reset --hard HEAD
```
