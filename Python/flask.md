1. Flask looks for factory function name create_app in init.py.

2. Activate virtual env
```cmd
pip install venv
python3 -m venv .venv
. .venv/bin/activate
```

3. MONGO URI
```cmd
mongodb+srv://username:password@cluster1.fa2ety3.mongodb.net/database_name?retryWrites=true&w=majority
```
4. Requirement.txt
```cmd
pip freeze > requirements.txt
pip install -r requirements.txt
```
5. Running
```cmd
flask --app flaskr run --debug
```
