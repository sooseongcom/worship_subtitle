# 영상예배 자막 프로그램
온라인 예배 화면에 날짜와 설교 제목, 성경 본문, 예배 시간 안내 등을 간단하게 띄울 수 있는 프로그램입니다. 날짜와 설교 제목은 프로그램을 이용하여 쉽게 수정할 수 있지만, 예배 시간 안내를 수정하기 위해서는 HTML 수정을 해야 하므로 교회 안에 코딩을 할 수 있는 사람이 1명 이상 필요합니다. 초기 설정이 완료되면 그 다음에는 코딩을 할 줄 모르는 사람도 설교 제목과 본문을 설정하여 방송실 사역을 감당할 수 있습니다.

## User Manual
### System Requirements
* OS: Windows
* Architecture: x86-64(AMD64)

### How to install
오른쪽 Realeses 목록의 설치 파일을 내려받아 설치합니다.\
웹 브라우저에서 차단 경고가 뜰 경우 **···** 클릭 후 **유지**를 클릭합니다.\
Windows에서 SmartScreen 경고가 뜰 경우 **추가 정보** 클릭 후 **실행**을 클릭합니다.

### 초기 설정
**%appdata%\\worship_subtitle\\subtitles\\index.html**에서 **div id="time"**을 찾아 수정합니다.

```html
<div id="time">
    <p class="scroll-left-text">
        여기에 교회 예배 시간 및 공지사항 작성
    </p>
</div>
```

### OBS Studio 설정
OBS Studio에서 소스 목록 아래의 [+] 버튼을 클릭→브라우저 클릭→새로 만들기 확인→아래와 같이 설정합니다.

* [x] 로컬 파일

URL: %appdata%\\worship_subtitle\\subtitles\\index.html\
너비: 1920\
"높이: 1080\
[확인]을 클릭한 다음 해당 브라우저 소스가 선택된 상태에서 [필터] 클릭→효과 필터 '크로마키' 추가(#0000ff 유사성 248로 설정)

## Developer Manual
### Files
* **subtitles**: the folder which will be installed at %appdata%\\worship_subtitle
  * index.html
  * stylesheet.css
* data.cpp: the code to modify data of HTML
* data.h
* kr2utf8.cpp: EUC-KR to UTF8 converter
* kr2utf8.h
* subtitle_setting.cpp: main function