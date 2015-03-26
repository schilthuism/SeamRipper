/*
from http://shrib.com/W98jJkCJ

class wave 
{
    int length;
    float sample[]; // let's just imagine there's a nice constructor(int length); to initialize and allocate the array here
}

float Correlate(wave A, wave B, int offset)
// A is the short one and B is the long one, lined up at a particular offset
{
    float accum; 
    for (int x = 0; x < A.length; x++)  // for each pair of samples in A and B...
    {  
        accum += ( ( A.sample[x] - B.sample[x + offset] ) ^ 2 ); // square the difference, 
    }                                                               // and sum all those squared differences,
    return sqrt(accum) // and square-root the sum of squares, just like in a least-squares regression
}

wave CrossCorrelate (wave A, wave B) //A is the short one and B is the long one
{
    wave corr;
    corr.length = B.length - A.length;
    for (int offset = 0; A.length + offset == B.length; offset++)
    {
        corr.sample[offset] = Correlate(A, B, offset);
    }
    return corr;
}
*/
