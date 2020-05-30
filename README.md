# ROS?

 - 오픈소스 로봇 소프트웨어 플랫폼. 
 - 로봇 어플리케이션들의 스케쥴링, 감시, 에러 처리, 이기종과의 통신 등을 관리해주는 메타 운영체제.
 - 빵빵한 라이브러리에 활발한 생태계를 갖추고 있다.

# ROS1 vs ROS2

[ROS2 개발 배경](http://design.ros2.org/articles/why_ros2.html), [ROS1과 ROS2의 차이점](http://design.ros2.org/articles/changes.html) 또는 [여기 이미지](https://www.theconstructsim.com/ko/infographic-ros-1-vs-ros-2-one-better-2/)를 참고.  [잘 정리해 둔 링크](https://snowdeer.github.io/ros2/2017/12/18/introduction-ros2/)도 있음.

 - **새로운 요구 사항들**
	 - 멀티 로봇
	 - MCU와의 연동
	 - Real-time 지원
	 - 네트워크 조건 완화
 - **운영체제**
	 - **ROS1**: Linux, Mac
	 - **ROS2**: Linux, Mac, Windows, RTOS
 - **언어**
	 - **ROS1**: C++ ~11 / Python 2
	 - **ROS2**: C++ ~17 / Python 3.5
- **Reusing existing middleware**
     - **ROS 1** uses a custom serialization format, a custom transport protocol as well as a custom central discovery mechanism. 
     - **ROS 2** has an abstract middleware interface, through which serialization, transport, and discovery is being provided. Currently all implementations of this interface are based on the DDS standard. This enables ROS 2 to provide various Quality of Service policies which improve communication over different networks.

등등 여러 사항들을 고려해 보았을 때 ROS를 처음 시작/도입하기에는 ROS2를 선택하는 것이 좋을 것 같음. 

# 개발 환경 구축
  - [ROS2 설치](https://index.ros.org/doc/ros2/Installation/#installationguide)
  - docker 활용
  - 등등
# 주요 개념
- **Node**
  최소 단위의 실행 가능한 프로세스

-  **Message**
  Node간 주고 받는 데이터. Message 통신 방법은 다음과 같은 것들이 있음
   - **Topic**
    Broadcasting 방식으로, Publisher가 송신, Subscriber가 수신한다.
	- **Service**
	1회성 요청으로, Client가 request를 보내면, Server가 response를 리턴한다.
	- **Action**
	기본 적으론 Service와 같으나, 일련의 중간결과를 보고하는 과정이 포함됨. Client가 goal을 전송하면 Server가 중간 과정을 수행함에 따라 feedback을 전송하고, 최종적으로 result를 전송하는 형태이다.

- **Package**
  하나 이상의 Node와 관련된 정보들의 묶음
