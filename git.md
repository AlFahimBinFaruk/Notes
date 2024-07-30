* [Sheet](https://www.geeksforgeeks.org/git-cheat-sheet/)

* git pull origin x
```
lets say you are now in y branch and want to update it with the changes in x branch then then you will use this command.
it will pull the changes from x branch and only update it in current branch you are working right now.
```
## while working in group project
```bash
# when you have made some changes in you branch push them in your remote branch
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

## When you are working in multiple accounts
1. **Viewing Git Configuration:**
   - **Local Configuration:** `git config --list --local`
   - **Global Configuration:** `git config --list --global`
   - **System Configuration:** `git config --list --system`

2. **SSH Configuration:**
   - **SSH Config File (`~/.ssh/config`):** Define multiple SSH keys for different GitHub accounts.
     ```plaintext
     # For Personal GitHub account
     Host github.com-personal
         HostName github.com
         User git
         IdentityFile ~/.ssh/id_ed25519

     # For Work GitHub account
     Host github.com-work
         HostName github.com
         User git
         IdentityFile ~/.ssh/id_rsa_xceed_h
     ```

3. **Updating Git Remote URL:**
   - **Check Current Remote URL:** `git remote -v`
   - **Update Remote URL:**
     - For Personal Account:
       ```bash
       git remote set-url origin git@github.com-personal:alfahim-xceed/Nzogo.git
       ```
     - For Work Account:
       ```bash
       git remote set-url origin git@github.com-work:alfahim-xceed/Nzogo.git
       ```
   - **Ensure the URL format is correct** and matches your SSH configuration alias.

4. **Verify SSH Key Access:**
   - **Add SSH Key to Agent:**
     ```bash
     ssh-add ~/.ssh/id_ed25519  # For Personal
     # or
     ssh-add ~/.ssh/id_rsa_xceed_h  # For Work
     ```
   - **Test SSH Connection:**
     ```bash
     ssh -T git@github.com-personal
     # or
     ssh -T git@github.com-work
     ```

5. **Handling Git Push Errors:**
   - **Error Example:** `Permission to <repo> denied to <username>`
   - **Common Fixes:** Ensure correct remote URL, correct SSH key, and correct GitHub account access.

6. **Clearing Credentials Cache (if needed):**
   ```bash
   git credential-cache exit
   ```

### **Summary**

- **Configure SSH:** Use different aliases for different GitHub accounts.
- **Update Git Remote URL:** Match the URL to the SSH config alias.
- **Verify Access:** Ensure the SSH key is used and correct GitHub access is set.
- **Handle Errors:** Ensure correct remote URLs and SSH configuration to resolve permission issues.

Feel free to keep these notes handy for future reference! If you have any more questions or need further clarification, just let me know.

