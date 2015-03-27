#include <X11/Xlib.h>
#include <unistd.h>

main()
{
  // Open a display.
  Display *d = XOpenDisplay(0);

  // Create the window
  Window w = XCreateWindow(d, DefaultRootWindow(d), 100, 100, 300, 300,
              0, CopyFromParent, CopyFromParent, CopyFromParent, 0, 0);

  // Show the window
  XMapWindow(d, w);
  XFlush(d);

  // Sleep long enough to see the window. A better programmer would set up
  // an event listener and wait for a MapNotify event but fuck that.
  
  sleep(1);

  // K let's try doing some shit
  XGCValues blackgcv, whitegcv;

  blackgcv.foreground=BlackPixel(d, DefaultScreen(d)); 
  blackgcv.background=WhitePixel(d, DefaultScreen(d)); 

  whitegcv.foreground=WhitePixel(d, DefaultScreen(d));
  whitegcv.background=BlackPixel(d, DefaultScreen(d)); 

	/* create the Graphics Contexts for our drawing operations */
  GC black=XCreateGC(d, w, GCForeground + GCBackground, &blackgcv);    
  GC white=XCreateGC(d, w, GCForeground + GCBackground, &whitegcv);    

  XClearWindow(d, w); XFlush(d);
  XFillRectangle(d, w, black, 0, 0, 300, 300);
  XFillRectangle(d, w, white, 50, 50, 200, 200);
  XFlush(d);

  sleep(10); // OBSERVE THE BEAUTIFUL SQUARE BEFORE YOU

  
  return 0;
}
