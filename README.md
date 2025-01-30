# htmlSearch
searches for a given term within html files in the directory it's placed in (plus subdirectories, iirc).
basically a cmd terminal opens, scans the directory for files (can take a while, could probably improve this by using a detached thread),
then asks for a term to search for in the directory and any subdirectories.
Only searches html files. Will crash if it comes accross any nonstandard characters in filenames (non-ascII, unicode characters, I think).
Could also fix that by changing my strings to wstrings when dealing with filenames, or something, but can't be bothered.
could also modify the program to search more than html files, probably make it possible to select from a list of compatible types or have user input a custom type,
but, again, can't be bothered.
