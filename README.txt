QSeriesHunter is a software which allows you to specify the TV series you are following in order to download them automatically for 

### Compiling QSeriesHunter

Requirements :
	* git
	* cmake 
	* Qt4 (4.7 or newer)

[1] Clone QSeriesHunter repository 
    > git clone git@github.com:docdoc/QSeriesHunter.git
    
[2] Install qjson library
    > cd QSeriesHunter
    > cd lib/qjson
    > mkdir build
    > cd build
    > cmake ..
    > make && make install
    
 [3] Compile QSeriesHunter
 	> cd QSeriesHunter
 	> mkdir build
 	> cd build
 	> cmake ..
 	> make