# ARM mbed cli2 Ubuntu 설치방법
기본적으로 우분투에는 python3가 있다.

1. sudo apt-get install python3-dev 다운로드 받는다.

2. 그 다음 home에 cmake_file을 만든다.
   ![Screenshot from 2024-04-15 16-45-41](https://github.com/ppareu/embededProgram/assets/127382049/68cca28b-6ad3-40ec-a86c-9ae0ad3b6426)

   위 사진에서 tar.gz파일을 다운로드 받고 방금 만든 cmake_file 디렉토리에 넣는다. 그런 다음 압축을 풀고 설치한다.

4. cmake를 설치하면 Ninja파일을 설치해야한다.
   sudo apt-get install ninja-build로 설치한다.

5. 그런 다음 GCC ARM을 설치해야한다. https://developer.arm.com/downloads/-/gnu-rm 위 사이트로 들어가서 최신버전을 다운받는다
   ![Screenshot from 2024-04-15 16-59-46](https://github.com/ppareu/embededProgram/assets/127382049/5dc23448-365a-4ed3-b993-6605a77d4772)
   
   다운을 받고 cmd 창에 cd /opt로 이동하고 /opt창에 방금 다운도르 한 파일을 들고와서 설치한다.
   설치를 다하면 gcc-arm-none-eabi-10.3-2021.10-x86_64-linux이런식으로 이름이 되어 있을건데 gcc-arm-none-eabi 이런식으로 파일이름 변경

7. 위 파일들을 다 설치했다면 마지막으로 st-link도 설치해야한다.
   sudo apt-get update
   sudo apt-get install git cmake build-essential libusb-1.0-0-dev

   git clone https://github.com/stlink-org/stlink.git
   cd stlink (파일로 이동해야함)

   cmake -DCMAKE_BUILD_TYPE=Release .
   make
   sudo make install
   sudo ldconfig

   which st-flash 명령어를 쳐서 /usr/local/bin/st-flash 뜨면 성공이다.

8. nano ~/.bashrc에 들어가서 맨아래 부분에
   
   export PATH=/opt/gcc-arm-none-eabi/bin:$HOME/.local/bin:$PATH
   alias mbed2='mbed-tools'

   이거를 그대로 입력해야함 그러면 이제 설정은 끝났다.

이제 파일을 만들어보자

1. mbed2 new 파일이름
2. cd 파일이름
3. mbed2 configure -m NUCLEO_F401RE -t GCC_ARM -b debug (Nucleo-f401re를 사용하므로 다른 보드는 mbed2 dectect로 보드 이름 확인)
4. cmake -S . -B cmake_build/NUCLEO_F401RE/debug/GCC_ARM -GNinja
5. code . (vscode로 코드를 짜고)
6. ninja -C cmake_build/NUCLEO_F401RE/debug/GCC_ARM (코드 파일 수정 시 컴파일)
7. sudo st-flash --connect-under-reset write cmake_build/NUCLEO_F401RE/debug/GCC_ARM/test1.bin 0x08000000

[serial moniter]

sudo cat /dev/ttyACM0 출력값 확인가능
