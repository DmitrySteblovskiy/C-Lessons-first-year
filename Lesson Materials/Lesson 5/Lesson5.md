
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
