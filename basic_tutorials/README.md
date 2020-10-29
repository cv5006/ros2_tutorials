Basic Tutorials
=================
ROS2의 기본적인 기능들을 실습한다.
 - Workspace 구성 및 Package 만들기
 - Topic, Serivce, Action 사용하기
 - Parameter 사용하기
 - RQT 사용하기
 - Bag 사용하기
 - ROS Doctor

[ROS2 공식 튜토리얼](https://index.ros.org/doc/ros2/Tutorials/#tutorials) 참고

## 1. 실습 환경 구성
실습을 위해 다음과 같이 몹시 간단한 시스템을 구성한다.

![system_for_tutorial](/images/basic_tutorials_system.png)

- PC
  - Ubuntu 18.04 (WSL1)
  - ROS2 Eloquent
  - 좋아하는 편집기
- HW
  - Arduino (Uno)
    - tutorial_hw.ino 사용
  - Sensor
    - 적당한 아날로그 센서
    - A0핀 사용
  - Motor
    - 파랗고 조그만 그 서보모터
    - D9핀 사용
  
  
## 2. 실습 내용
- ROS2를 이용해
  - 센서로 모터를 조작 해본다
  - 지정한 프로파일대로 모터를 움직여본다 (생략)
  - 지정한 위치로 모터를 이동시켜본다

### 2.1. Workspace 구성 및 Package 만들기
- workspace folder
  - build
  - install
    - setup.bash
  - log
  - src
    - package
      - source files
      - package.xml
      - CMakeLists.txt, or, setup.py & setup.cfg
  - launch
    - launch files
  - bag
    - ros bag files

### 2.2. Topic, Service, Action 사용하기
- 인터페이스 이해하기
- 노드 맹글기
- 터미널 커맨드
#### 2.2.1. Topic publisher/subscriber
- 메시지 인터페이스
  - std_msgs
#### 2.2.2. Serivce server/client
- 서비스 인터페이스
  - std_srvs
#### 2.2.3. Action server/client
- 액션 인터페이스
  - 커스텀 인터페이스 만들기
### 2.3. Parameter 사용하기
### 2.4. Launch file 만들기
- launch
- launch.ros
- where the hell the docs are
### 2.5. RQT 사용하기
### 2.6. Bag 사용하기
- record
- playback
### 2.7 ROS Doctor
  
  
## 3. What's More!
### 3.1. ROS with Docker
### 3.1. MicroROS

