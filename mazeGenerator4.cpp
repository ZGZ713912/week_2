#include<bits/stdc++.h>
#include <fstream>
using namespace std;
int n;
int m;
int tw;
int mgl;
int lineW; 
int hx[100005];
int hy[100005];
bool a[1005][1005];
int x,y;
int Lastx,Lasty;
int dir,step;
const int BYTES_PER_PIXEL = 3;
const int FILE_HEADER_SIZE = 14;
const int INFO_HEADER_SIZE = 40;
void generateBitmapImage(unsigned char* image, int height, int width, char* imageFileName);
unsigned char* createBitmapFileHeader(int height, int stride);
unsigned char* createBitmapInfoHeader(int height, int width);
int height,width;
char imageFileName[] = "maze\\0000.bmp";
int main(){
	cout<<"�Թ�������V1.0"<<endl;
	cout<<"�������Թ��ĳ��� ";
	cin>>m;
	cout<<"�������Թ��Ŀ��� ";
	cin>>n;
	cout<<"�������Թ���·���� ";
	cin>>tw;
	cout<<"�������Թ�ǽ�ں�� ";
	cin>>lineW;
	lineW--;
	cout<<"������Ŀ���Թ����� "; 
	cin>>mgl;
	height = tw*n+lineW+1;
	width = tw*m+lineW+1;
	cout<<"�Թ��ֱ���:"<<height<<"x"<<width<<endl;
	system("pause");
	cout<<"���������Թ�......";
	int end,start;
	start=time(NULL); 
	while(end-start<1){
		end=time(NULL);
		rand();
	}
	for(int  k = 1;k<=mgl;k++){
		for(int i = 0;i<1005;i++){
			for(int j = 0;j<1005;j++){
				a[i][j]=0;
			}
		}
		for(int i = 0;i<100005;i++){
			hx[i]=0;
			hy[i]=0;
		}
		x=0,y=0;
		Lastx=0,Lasty=0;
		dir = 0;
		step = 0;
		step=0;
	    unsigned char image[height][width][BYTES_PER_PIXEL];
	    
	    if(k<10){
		   	imageFileName[8]=k+'0';
		   	imageFileName[7]='0';
		   	imageFileName[6]='0';
		   	imageFileName[5]='0';
		}
		else if(k<100){
		   	imageFileName[8]=(k%10)+'0';
		   	imageFileName[7]=(k/10)+'0';
		   	imageFileName[6]='0';
		   	imageFileName[5]='0';
		}
		else if(k<1000){
			imageFileName[8]=(k%10)+'0';
		   	imageFileName[7]=(k/10%10)+'0';
		   	imageFileName[6]=(k/100)+'0';
		   	imageFileName[5]='0';
		}
		else if(k<10000){
			imageFileName[8]=(k%10)+'0';
		   	imageFileName[7]=(k/10%10)+'0';
		   	imageFileName[6]=(k/100%10)+'0';
		   	imageFileName[5]=(k/1000)+'0';
		}
		for (int i = 0; i < height;  i++) {
	        for (int j = 0; j < width; j++) {
	            image[i][j][2] = 255;//red
	            image[i][j][1] = 255;//green
	            image[i][j][0] = 255;//blue
	        }
	    }
	    for(int j = 0;j<tw;j++){
	    	for(int i = 0; i < tw;  i++) {
	        
		        image[j][i][2] = 255;             ///red
		        image[j][i][1] = 0;              ///green
		        image[j][i][0] = 0; ///blue
		        
		    }
		}
		for(int j = height-tw;j<height;j++){
	    	for(int i = width-tw; i < width;  i++) {
	        
		        image[j][i][2] = 0;             ///red
		        image[j][i][1] = 0;              ///green
		        image[j][i][0] = 255; ///blue
		        
		    }
		}
	    for(int j = 0;j<height;j+=tw){
	    	for(int i = 0; i < width;  i++) {
	        	for(int l = j;l<=j+lineW;l++){
	        		image[l][i][2] = 0;//red
		        	image[l][i][1] = 0;//green
		        	image[l][i][0] = 0;//blue
				}
		    }
		}
	    for(int j = 0;j<width;j+=tw){
	    	for(int i = 0; i < height;  i++) {
	        	for(int l = j;l<=j+lineW;l++){
	        		image[i][l][2] = 0;//red
		        	image[i][l][1] = 0;//green
		        	image[i][l][0] = 0;//blue
				}
		        
		    }
		}
		a[0][0]=1;
		while(1){
			step++;
			while(1){
				bool sl = 0;
				int l2x=x;
				int l2y=y;
				for(int i = 0;i<=3;i++){
					if(i==0) y--;
					else if(i==1) y++;
					else if(i==2) x--;
					else if(i==3) x++;
					if(x>=0&&x<n&&y>=0&&y<m&&a[x][y]==0){
						sl=1;
					}
					x=l2x;
					y=l2y;
				}
				if(sl==0){
					x=hx[step-1];
					y=hy[step-1];
					Lastx=x;
					Lasty=y;
					step--;
					dir=4;
					if(step<0) break;
				}
				
				dir=rand()%4;
				int lx=x;
				int ly=y;
				if(dir==0) y--;
				else if(dir==1) y++;
				else if(dir==2) x--;
				else if(dir==3) x++;
				
				
				
				if(x>=0&&x<n&&y>=0&&y<m&&a[x][y]==0){
					if(dir==0){
						for(int i = x*tw+1+lineW; i < x*tw+tw;  i++) {
							for(int l = (y+1)*tw;l<=(y+1)*tw+lineW;l++){
				        		image[l][i][2] = 255;//red
					        	image[l][i][1] = 255;//green
					        	image[l][i][0] = 255;//blue
							}
					   	}
					   	
					}
					else if(dir==1){
						for(int i = x*tw+1+lineW; i < x*tw+tw;  i++) {
							for(int l = y*tw;l<=y*tw+lineW;l++){
				        		image[l][i][2] = 255;//red
					        	image[l][i][1] = 255;//green
					        	image[l][i][0] = 255;//blue
							}
					   	}
					}
					else if(dir==2){
						for(int i = y*tw+1+lineW; i < y*tw+tw;  i++) {
							for(int l = (x+1)*tw;l<=(x+1)*tw+lineW;l++){
				        		image[i][l][2] = 255;//red
					        	image[i][l][1] = 255;//green
					        	image[i][l][0] = 255;//blue
							}
					   	}
					}
					else if(dir==3){ 
						for(int i = y*tw+1+lineW; i < y*tw+tw;  i++) {
							for(int l = x*tw;l<=x*tw+lineW;l++){
				        		image[i][l][2] = 255;//red
					        	image[i][l][1] = 255;//green
					        	image[i][l][0] = 255;//blue
							}
					   	}
					}
					Lastx=x;
					Lasty=y;
					break;
				}
				else{
					x=lx;
					y=ly;
				}
				
				
			}
			if(step<0) break;
			hx[step]=x;
			hy[step]=y;
			a[x][y]=1;
			
		}
		generateBitmapImage((unsigned char*) image, height, width, imageFileName);
		system("cls");
	    cout<<"�����"<<k<<"���Թ�"<<endl;
	}
		cout<<mgl<<"���Թ�����ɣ�"<<endl;
		system("pause");
		return 0;
}
void generateBitmapImage (unsigned char* image, int height, int width, char* imageFileName)
{
    int widthInBytes = width * BYTES_PER_PIXEL;

    unsigned char padding[3] = {0, 0, 0};
    int paddingSize = (4 - (widthInBytes) % 4) % 4;

    int stride = (widthInBytes) + paddingSize;

    FILE* imageFile = fopen(imageFileName, "wb");

    unsigned char* fileHeader = createBitmapFileHeader(height, stride);
    fwrite(fileHeader, 1, FILE_HEADER_SIZE, imageFile);

    unsigned char* infoHeader = createBitmapInfoHeader(height, width);
    fwrite(infoHeader, 1, INFO_HEADER_SIZE, imageFile);

    int i;
    for (i = 0; i < height; i++) {
        fwrite(image + (i*widthInBytes), BYTES_PER_PIXEL, width, imageFile);
        fwrite(padding, 1, paddingSize, imageFile);
    }

    fclose(imageFile);
}

unsigned char* createBitmapFileHeader (int height, int stride)
{
    int fileSize = FILE_HEADER_SIZE + INFO_HEADER_SIZE + (stride * height);

    static unsigned char fileHeader[] = {
        0,0,     /// signature
        0,0,0,0, /// image file size in bytes
        0,0,0,0, /// reserved
        0,0,0,0, /// start of pixel array
    };

    fileHeader[ 0] = (unsigned char)('B');
    fileHeader[ 1] = (unsigned char)('M');
    fileHeader[ 2] = (unsigned char)(fileSize      );
    fileHeader[ 3] = (unsigned char)(fileSize >>  8);
    fileHeader[ 4] = (unsigned char)(fileSize >> 16);
    fileHeader[ 5] = (unsigned char)(fileSize >> 24);
    fileHeader[10] = (unsigned char)(FILE_HEADER_SIZE + INFO_HEADER_SIZE);

    return fileHeader;
}

unsigned char* createBitmapInfoHeader (int height, int width)
{
    static unsigned char infoHeader[] = {
        0,0,0,0, /// header size
        0,0,0,0, /// image width
        0,0,0,0, /// image height
        0,0,     /// number of color planes
        0,0,     /// bits per pixel
        0,0,0,0, /// compression
        0,0,0,0, /// image size
        0,0,0,0, /// horizontal resolution
        0,0,0,0, /// vertical resolution
        0,0,0,0, /// colors in color table
        0,0,0,0, /// important color count
    };

    infoHeader[ 0] = (unsigned char)(INFO_HEADER_SIZE);
    infoHeader[ 4] = (unsigned char)(width      );
    infoHeader[ 5] = (unsigned char)(width >>  8);
    infoHeader[ 6] = (unsigned char)(width >> 16);
    infoHeader[ 7] = (unsigned char)(width >> 24);
    infoHeader[ 8] = (unsigned char)(height      );
    infoHeader[ 9] = (unsigned char)(height >>  8);
    infoHeader[10] = (unsigned char)(height >> 16);
    infoHeader[11] = (unsigned char)(height >> 24);
    infoHeader[12] = (unsigned char)(1);
    infoHeader[14] = (unsigned char)(BYTES_PER_PIXEL*8);

    return infoHeader;
}
