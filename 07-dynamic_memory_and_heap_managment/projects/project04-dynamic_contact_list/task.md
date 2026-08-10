### 10.  ⭐ PROJECT: Dynamic Contact List
Build a program that stores a user-defined number of contacts.
Each contact has a **dynamically sized name** and a **dynamically sized email**.

Conceptually:
```text
contacts
│
▼
┌────────────┬────────────┬────────────┐
│ contact[0] │ contact[1] │ contact[2] │
└─────┬──────┴─────┬──────┴─────┬──────┘
      │            │            │
      ▼            ▼            ▼
   "Alice"       "Bob"       "Charlie"
      │            │            │
      ▼            ▼            ▼
  "a@x.com"    "b@x.com"    "c@x.com"
```
##### Requirements
Your program should:
1. Ask how many contacts the user wants.
2. Dynamically allocate the **outer pointer array**.
3. For each contact:
	* Ask for a name.
	* Dynamically allocate exactly enough memory for it.
	* Store it.
	* Ask for an email.
	* Dynamically allocate exactly enough memory for it.
	* Store it.
4. Print every contact and its memory addresses.
5. Free **every inner allocation**.
6. Free the **outer allocation**.
7. Set freed pointers to `NULL` where appropriate.
8. 
You can design the structs/functions however you want.
##### Restrictions
Don't use:
* fixed-size `name[100]`
* fixed-size `email[100]`
* `strdup()`
* a giant 4096-byte input buffer

You **can** use the concepts you've already learned, including `malloc`, `memcpy`, `strlen`, `getchar`, structs, pointers, and functions.