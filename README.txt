QSeriesHunter is a software which allows you to specify the TV series you are following in order to download them automatically for 

### Compiling QSeriesHunter

Requirements :
	* git
	* cmake 
	* Qt4 (4.7 or newer)

Requirements Windows :
        * MinGW
	* Visual Studio 2010 express
	* NSIS for packaging

[0] On Win32 open the cmd line provided by Qt in Desktop/MinGW

[1] Clone QSeriesHunter repository 
    > git clone git@github.com:docdoc/QSeriesHunter.git
    
[2] Install qjson library
    > cd QSeriesHunter
    > cd lib/qjson
    > mkdir build
    > cd build
    > cmake ..
    > compile and install : 
         + On unix  : make && make install  
         + On Win32 : mingw32-make and mingw32-make install
    
 [3] Compile QSeriesHunter
 	> cd QSeriesHunter
 	> mkdir build
 	> cd build
 	> run cmake : 
            + On Unix cmake ..
            + On Win32 cmake -G "MinGW Makefiles"
 	> make or mingw32-make


### Creating package
[1] Run cmake with -DCMAKE_BUILD_TYPE=Release
    
[2] Compile and install : 
       + On unix  : make  
       + On Win32 : mingw32-make
    
[3] Run CPack
 	> cpack (-V for verbose)
