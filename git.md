* [Sheet](https://www.geeksforgeeks.org/git-cheat-sheet/)

* git pull origin x
```
lets say you are now in y branch and want to update it with the changes in x branch then then you will use this command.
it will pull the changes from x branch and only update it in current branch you are working right now.
```
* while working in group project
```
when you have made some changes in you branch push them in your remote branch
git add .
git commit -m""
git push origin developer/al-fahim


git fetch # to update the tracking

git checkout main # goto your local main branch
git pull origin main # update your local main branch with remote main branch


git checkout developer/al-fahim # goto your developer branch
git pull origin developer/al-fahim 

git merge origin/main # merge your local developer branch with local remote branch
# if there is git conflict goto files and handle them.
git push origin developer/al-fahim # now push those changes in developer branch

git checkout main # goto main branch
git merge developer/al-fahim # merge 
git push origin main

```
