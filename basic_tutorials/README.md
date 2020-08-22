# Basic Tutorials
다음과 같은 ROS의 주요 기능을 구현해 본다.
 - Workspace 구성 및 Package 만들기
 - Node 만들기
 - Topic publisher/subscribeer 만들기
 - Serivce server/client 만들기
 - Action 사용하기
 - Parameter 사용하기

[ROS2 공식 튜토리얼](https://index.ros.org/doc/ros2/Tutorials/#tutorials) 참고

## 실습 환경
실습을 위해 다음과 같이 몹시 간단한 시스템을 구성한다.

![system_for_tutorial](/images/basic_tutorials_system.png)

 - PC
   - Ubuntu 18.04
   - ROS2 Eloquent
   - VS Code + ROS extension (C/C++ 당연히!)
 - Arduino (Uno)
   - src/arduino_test_code 사용
   - 시리얼 통신으로 센서 값을 송신, 모터 출력 값을 수신한다.
 - Sensor
   - 적당한 아날로그 센서
 - Motor
   - 파랗고 조그만 그 서보모터


##
