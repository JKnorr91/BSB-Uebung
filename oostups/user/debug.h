
#ifndef __debug_include__
#define __debug_include__

class Debug 
 
 {
private:
    Debug (const Debug &copy); // Verhindere Kopieren

public:
	Debug();

    void out(int x, int y, char* text);

 };
extern Debug debug;

#endif
