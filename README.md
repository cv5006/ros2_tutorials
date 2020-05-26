# ROS?

 - 오픈소스 로봇 소프트웨어 플랫폼. 
 - 로봇 어플리케이션들의 스케쥴링, 감시, 에러 처리, 이기종과의 통신 등을 관리해주는 메타 운영체제.
 - 빵빵한 라이브러리에 활발한 생태계를 갖추고 있다.

# ROS1 vs ROS2

[ROS1과 ROS2의 차이점](http://design.ros2.org/articles/changes.html) 또는 [여기](https://www.theconstructsim.com/ko/infographic-ros-1-vs-ros-2-one-better-2/)를 참고.  [여기](https://snowdeer.github.io/ros2/2017/12/18/introduction-ros2/)도 있음.

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
[https://index.ros.org/doc/ros2/Installation/#installationguide](https://index.ros.org/doc/ros2/Installation/#installationguide)

# 주요 개념
- Node
- Package
- Message
	- Topic
	- Service
	- Action
