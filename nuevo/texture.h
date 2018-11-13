
#if _WIN32
	#include "Main.h"
#else
	#include "NVSMain.h"
#endif

class CTexture
{
public:
	char* name;
	unsigned char*  imageData;
	int		bpp;			// Image Color Depth In Bits Per Pixel
	int		width;			// Image Width
	int		height;		    // Image Height
	unsigned int    GLindex;

	bool LoadTGA(char* filename);		// Loads A TGA File Into Memory
	bool LoadBMP(char* filename);
	void BuildGLTexture();
	void ReleaseImage();
};
