/* 
Filename: bmpBasicExample.h
*/

// The Pixel structure stores the color information in a single pixel as R,G,B values.
struct Pixel
{
	unsigned char R,G,B;
};

/* The bmpFileHeader structure contains one kind of header information about a bitmap file. 
This is stored at the beginning of the file, BEFORE the actual pixel data . */
struct bmpFileHeader
{
    short fileId;
    int size;
    short res1;
    short res2;
    int offset;
};

/* The bmpInfoHeadeer structure contains ANOTHER kind of header information about a bitmap file. 
This is also stored before the pixel data, but after the file header.*/
struct bmpInfoHeader
{
    int size;
    int width;
    int height;
    short planes;
    short bitCount;
    int comp;
    int img_size;
    int hr;
    int vr;
    int color;
    int imp_color;
    int cMap;
};

/* The bitmapImage structure contains the complete information about an bitmap file */
struct bitmapImage
{
    struct bmpFileHeader filehead;
    struct bmpInfoHeader infohead;
    struct Pixel pixelMatrix[300][300];
	int valid; // This is optional, it can indicate whether valid information is stored in the structure.
};


// Puts a pixel into a bitmap file.
void putPixel(FILE *ptr, struct Pixel pixel);


// Returns a single pixel from the current location of a file.
struct Pixel getPixel(FILE *ptr);


// getImage acepts the filename of a bitmap and returns the complete image information as a "struct bitmapImage".
// The valid variable can be set to 0 if reading the image was successful.
struct bitmapImage getImage(char inputFilename[]);


// putImage takes image information and stores it in a bitmap file.
// This can return 0 if it is successful.
int putImage(char outputFilename[], struct bitmapImage bmpImg);  
