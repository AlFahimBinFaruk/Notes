### Django
* [Django For Everybody - Full Python University Course - freecodecamp](https://www.youtube.com/watch?v=o0XbHvKxw7Y)
* [Python Django 7 Hour Course - traversy media](https://www.youtube.com/watch?v=PtQiiknWUcI)
* [My Project](https://github.com/AlFahimBinFaruk/Djanog_CRUD_Auth_MVT)
### DRF
* [Build a Django REST API with the Django Rest Framework. Complete Tutorial.](https://www.youtube.com/watch?v=c708Nf0cHrs)
* [My Project](https://github.com/AlFahimBinFaruk/DRF_Tutorial)

### Commands

1. Install virutal environment on pc if not installed
```cmd
pip install virtualenv
```

2. Create an virtual env
```cmd
python3 -m venv myvenv

venv myenv
```

3. Activate env
```cmd
source myvenv/bin/activate
```

4. Install Django
```cmd
pip install django
```

5. Create new project
```cmd
django-admin startproject <project_name>
```

6. Run server
```cmd
cd/project

python manage.py runserver

python manage.py runserver [--port <port_number>]
```

7. Create a new app
```cmd
python manage.py startapp <app_name>
```

8. Identifies changes to your models (creation, deletion, field modifications) and translates them into database schema migrations.
```cmd
python manage.py makemigrations
```

9. Applies the generated database schema migrations to your database.
```cmd
python manage.py migrate
```

9. Create super user
```cmd
python manage.py createsuperuser --username <username> --email <email>
```

10. Others
```cmd
python manage.py showmigrations

django-admin help

django-admin help <command_name>

```













