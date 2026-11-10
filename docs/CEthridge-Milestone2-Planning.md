> Use this worksheet to plan the next phase of your project **before you begin coding**
> Be clear, specific, and intentional—this will guide your development this week.

---
## 📌 Project Overview

**Project Name:**
→   Pathfinder 1e Character Builder
  
**What does your program currently do? (1–3 sentences)**   
→   The program currently provides a menu allowing the user to select between creating a new character, viewing the current character, a placeholder option to load a character, or exit the application.

---
## 🔍 Current Progress Check  
  
**What is working right now?**   
→   Creating a new character prompts the user to select from several options at each stage of character creation and is fully integrated. View current character either shows the summary page for the created character or returns the user to the menu after informing them no character has been created.
  
**What is NOT working or incomplete?**   
→   Feat and Spell options are currently restricted to those beginning with "A".
  
**What feels confusing or messy in your code?**   
→   The user can currently assign any values they want for Ability Scores, and can select any number of Spells of any Spell level from available options.

---
## 🚀 Feature Planning  
  
List the features you plan to add or improve this week.  
  
### Feature 1  
**Name:**   
→   Create New Character menu option
  
**What does this feature do?**   
→   Prompts the user to select from several options at each stage of character creation.
  
**Why is this feature important?**   
→   It is the main purpose of the application.
  
---
### Feature 2  
**Name:**   
→   Character class
  
**What does this feature do?**   
→   Allows the application to save the user's selected options in memory.
  
**Why is this feature important?**   
→   Without this, the created character is immediately deleted after completing creation.
  
---
  
### Feature 3 (optional)  
**Name:**   
→   
  
**What does this feature do?**   
→   
  
**Why is this feature important?**   
→   
  
---
## 🧩 System Design Updates  
  
**Will you need to create any new classes? If so, which ones?**   
→   No.
  
**Will you modify any existing classes? How?**   
→   I need to add the remaining Feats and Spells to their respective classes. The groundwork is in place for this, I just need to add the functions.
  
**What data structures will you use (vectors, 2D vectors, etc.)?**   
→   Vectors and maps
  
---
## 🔄 Program Flow  
  
**Describe how a user interacts with your program:**  
  
1. Program starts →   Menu presented with 4 options
2. User chooses →   One of the menu options
3. Program responds →   It goes through a createCharacter, viewCharacter, loadCharacter, or closes the program, respective of the option selected
4. Loop/next step →   If createCharacter, prompts user through creation process. If viewCharacter, either shows the summary of the current character or informs the user one has not been created yet. If loadCharacter, informs the user the ability to load hasn't been implemented yet. If exit, closes the application.
  
---
## 🎯 Usability Improvements  
  
How will you make your program easier to use this week?  
  
- Clearer prompts:   
→   Prompts directly inform user to select from available options presented.
  
- Better error handling:   
→   Invalid choices now direct the user to select again from valid options.
  
- Improved menu/navigation:   
→   Menu is straightforward and simple to navigate.
  
---
## ⚠️ Potential Challenges  
  
**What do you think will be the hardest part this week?**   
→   Editing the creation process to prevent duplicate selections was the hardest part so far.
  
**What is your plan if you get stuck?**   
→   Ask for feedback from instructors or peers.
  
---
  
## 📈 Level Up Goal  
  
**What skill are you focusing on improving this week?**   
→   Debugging more often
  
**What will you do to improve it?**   
(e.g., tutorial, practice, debugging, office hours)   
→   Debug after small changes and more often, rather than after a large change or implementation only.
  
---
## 🗓️ Task Breakdown (GitHub Issues Planning)  
  
List the tasks you plan to create as GitHub Issues:  
  
- [ ]   Character class
- [ ]   Remove SavingThrows object, as it is unnecessary
- [ ]   Finish Feats and Spells (if time permits)
  
---
  
## 🔥 Final Check  
  
Before you start coding, ask yourself:  
  
- [ ] Do I know what I’m building this week?   
- [ ] Do I know where to start?   
- [ ] Did I break my work into small tasks?   
  
If yes → start coding 🚀   
If no → refine your plan first   
  
---
## 😈 Final Thought  
  
> Plan it now… or debug it later.