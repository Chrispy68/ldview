cd tools\build\v2\engine
call build
cd bin.*
copy bjam.exe ..\..\..\..\..
cd ..\..\..\..\..
bjam --with-date_time --with-thread link=static runtime-link=static variant=release stage release debug
rem x64
rem bjam --with-date_time --with-thread architecture=x86 address-model=64 link=static runtime-link=static variant=release stage release debug
