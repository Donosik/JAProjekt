#ifndef CPPDLL_LIBRARY_H
#define CPPDLL_LIBRARY_H

#if BUILDING_DLL
# define DLLIMPORT __declspec (dllexport)
#else /* Not BUILDING_DLL */
# define DLLIMPORT __declspec (dllimport)
#endif /* Not BUILDING_DLL */

extern "C"
{
int DLLIMPORT dilatation(int x1,int x2,int x3,int x4,int x5,int x6,int x7,int x8);
int DLLIMPORT erosion(int x1,int x2,int x3,int x4,int x5,int x6,int x7,int x8);
}
#endif CPPDLL_LIBRARY_H
