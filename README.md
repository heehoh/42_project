# 도커 단계별 지침.

- 컨테이너로 이미지 빌드 및 실행하기
- Docker Hub를 사용해서 이미지 공유하기
- 데이터베이스가 있는 여러 컨테이너를 사용하여 Docker 어플리케이션 배포하기
- Docker Compose를 사용하여 어플리케이션 실행하기

## 컨테이너란
컨테이너는 호스트 머신에서 실행되는 샌드박스가 적용된 프로세스로, 해당 호스트 머신에서 실행되는 다른 모든 프로세스로부터 격리됩니다.
이러한 격리는 커널 네임스페이스와 cgroup(Control group - 리소스 사용량 결정)을 활용하며, 이는 오랫동안 Linux에서 사용되어 온 기능입니다.
Docker는 이런 기능을 사용하기 쉽게 만듭니다.

요약하자면 컨테이너는
- 실행가능한 이미지 인스턴스입니다. Docker API 또는 CLI를 사용하여 컨테이너를 생성, 시작, 중지, 이동 또는 삭제할 수 있습니다.
- 로컬 머신, 가상머신에서 실행하거나 클라우드에 배포할 수 있습니다.
- 이식성이 뛰어나 모든 OS에서 실행할 수 있습니다
- 다른 컨테이너와 격리되어 있으며 자체 소프트웨어, 바이너리, 구성 등을 실행합니다.
- 컨테이너는 루트(chroot)의 확장 버전이라고 생각하시면 됩니다. 파일 시스템은 이미지에서 가져옵니다.
  
## 이미지란 무엇인가요?

실행중인 컨테이너는 격리된 파일 시스템을 사용합니다. 이 격리된 파일시스템은 이미지로 제공되며, 이미지에는 모든 종속성, 구성, 스크립트, 바이너리 등 애플리케이션을 실행하는데 필요한 모든 것이 포함되어야 합니다. 이미지에는 환경 변수, 실행할 기본 명령 및 기타 메타데이터와 같은 컨테이너에 대한 기타 구성도 포함됩니다.

도커파일로 이미지 생성
도커파일은 FROM 명령어로 시작해야 합니다. 이는 파서 시지어 주석 및 전역범위의 ARG 다음에 올 수 있습니다. FROM 명령은 빌드하는 부모 Imageopen_in_new를 지정합니다. FROM 앞에 하나 이상의 ARG 명령어만 올 수 있고 도커 파일 FROM 줄에 사용되는 인수를 선언합니다.