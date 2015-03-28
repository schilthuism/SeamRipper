#include <X11/Xlib.h>
#include <unistd.h>
#include <math.h>


void drawWave( float wave[], int wavelen, Display *d, Window w, GC gc, 
                int xoffset, int yoffset, int height, int width)
{
  int i, samp;
  for (i=0; i<width; i++)
    {
       float sampmax = 0;   // for each column in the wave image, we're going to
       float sampmin = 0;   // iterate over all the samples represented by that
       int firstsamp = (i * wavelen) / width;                        // column.
       int lastsamp = (((i + 1) * wavelen) / width) - 1;

       for (samp=firstsamp; samp <= lastsamp; samp++)
        { 
          if (wave[samp] > sampmax)
            sampmax = wave[samp];
          if (wave[samp] < sampmin)
            sampmin = wave[samp];
        }

        int x, ymid, y1, y2;
        x = xoffset + i;
        ymid = yoffset + (height/2);
        y1 = ymid + (sampmax * height / 2);
        y2 = ymid + (sampmin * height / 2);

      XDrawLine(d, w, gc, x, y1, x, y2);
    }
  XFlush(d);
}



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

  //////////HOLD ONTO YOUR HAT SHIT IS ABOUT TO GET BONKERS//////////

  float davethesinewave[500];
  int k;
  for (k=0;k<500;k++)
    {
      davethesinewave[k] = sin(k);
    }

  drawWave( davethesinewave, 500, d, w, black, 
               50, 50, 200, 200 );

  sleep(10); // OBSERVE THE BEAUTIFUL WAVE BEFORE YOU
  
  return 0;
}

