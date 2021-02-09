# STM32
STM32 예제입니다. ___  
___
작성자: 박광렬   ___
  * @copyright Copyright (c) Park Kwangryeol All right reserved.   ___
  모든 저작권은 작성자 박광렬에게 있습니다.   ___

# 주의 사항
  * 대부분의 소스 코드가 제 컴퓨터 환경에 맞춰져 있습니다.     ___
  따라서 다음 요소들을 직접 수정해주시길 바랍니다.   ___
  __어떻게 하는지 모르시는 분들은 가장 아래에 나와 있는 제 블로그로 이동하셔서 댓글로 질문을 남겨주시기를 바랍니다.__   ___
___
  1. Options -> C/C++ Compiler -> Preprocessor   ___
___
___
  * startup_stm32f10x_hd_vl.s 파일   ___
    startup_stm32f10x_hd_vl.s은 6장 이후로 필수적으로 필요한 파일입니다.   ___
    하지만 제가 소유하고 있는 코드가 아니기 때문에 링크를 걸어 두겠습니다.   ___
    Link: [소스코드][githublink]   ___
    [githublink]: https://github.com/tuanpmt/CMSIS "Go to github"   ___
___
    적절한 곳(문서)에 압축을 푸신 후, CM3 -> DeviceSupport -> ST -> STM32F10x -> startup -> iar에 가면 해당 파일이 있습니다.  ___
    해당 위치에 가서 startup_stm32f10x_hd_vl.s가 있는 위치의 주소를 복사하신 후,   ___
    Preprocessor에 있는 E:\ARM\res\CMSIS\CM3\DeviceSupport\ST\STM32F10x\startup\iar 경로가 있다면, 위에서 복사한 경로로 수정해 주시기를 바랍니다.   ___
___
  * res -> cortex_m3 파일   ___
    res 파일 아래 cortex_m3파일은 수많은 레지스터 값들이 저장되어 있는 파일입니다.   ___
    이또한 경로를 확인하셔서 cortex_m3 파일의 주소를 복사하신 후, Preprocessor란에 E:\ARM\res\cortex_m3 경로가 있다면, 복사한 경로로 수정해 주시기를 바랍니다.   ___
___
  * res -> stm32 파일   ___
    res 파일 아래 stm32파일은 수많은 레지스터 값들이 저장되어 있는 파일입니다.   ___
    이또한 경로를 확인하셔서 stm32 파일의 주소를 복사하신 후, Preprocessor란에 E:\ARM\res\stm32 경로가 있다면, 복사한 경로로 수정해 주시기를 바랍니다.   ___
___
# 강좌 바로 가기   
  Link: [stm32 레지스터 직접 접근][bloglink]   ___
  [bloglink]: https://pkr7098.tistory.com/159 "Go to pkr7098.tistory.com"   ___
