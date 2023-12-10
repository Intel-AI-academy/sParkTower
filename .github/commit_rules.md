# Commit message rules

- 제목과 본문을 한 줄 띄어 구분
- 제목은 50자 이내
- 제목 첫 글자는 대문자
- 제목 끝에 마침표 X
- 제목은 명령문으로, 과거형 X
- 본문의 각 행은 72자 이내 (줄바꿈 사용)
- 본문은 어떻게 보다 무엇을, 왜에 대하여 설명

## Commit message template
```
  <type>: <subject>
  
  <body>
  
  <footer>
```

### Types

|Types|explain|
|----|----|
|feat| 새로운 기능 추가, 기존의 기능을 요구 사항에 맞추어 수정
|fix | 기능에 대한 버그 수정
|build | 빌드 관련 수정
|chore | 패키지 매니저 수정, 그 외 기타 수정 ex) .gitignore
|ci | CI 관련 설정 수정
|docs | 문서(주석) 수정
|style | 코드 스타일, 포맷팅에 대한 수정
|refactor | 기능의 변화가 아닌 코드 리팩터링 ex) 변수 이름 변경
|test | 테스트 코드 추가/수정
|release | 버전 릴리즈

### Subject

  ex) feat: Add some files
  
### Body

  - 선택사항이기 때문에 모든 커밋에 본문을 작성할 필요는 없다
  - 부연설명이 필요하거나 커밋의 이유를 설명할 경우 작성
  - 72자를 넘기지 않게 작성
  - 본문은 어떻게 변경했는지 보다 무엇을 변경했는지, 왜 변경했는지 에 맞추어 작성
  - 
### Footer
  - 선택사항이기 때문에 모든 커밋에 꼬리말을 작성할 필요는 없다!
  - issue tracker id를 작성할 때 사용
  - 유형: #이슈 번호 형식으로 작성
  - 유형은 다음 중 하나를 사용

|Tags | Explain|
|----|----|
|Fixes | 이슈 수정 중 (아직 해결되지 않은 경우)|
|Resolves |이슈를 해결했을 때 사용|
|Ref | 참고할 이슈가 있을 때 사용|
|Related to| 해당 커밋에 관련된 이슈 번호 (아직 해결되지 않은 경우)|
