# data_structure

> 2019 2학기 자료구조 수업

# 텀프로젝트
음원자료 관리 시스템

## 시스템 메뉴얼
### 메인화면
![image](https://user-images.githubusercontent.com/55576129/115740597-f048f800-a3c9-11eb-9ed4-3cbdfe5156b9.png)

### 리스트 목록
- MasterList : 곡의 모든 정보가 담겨져 있는 리스트
- PlayList : 플레이된 곡의 정보가 담겨져 있는 리스트
- SingerList : 가수의 정보와 그 가수의 곡 목록이 담겨져 있는 리스트
- FolderList : 폴더들이 있는 리스트

## 기능 설명
### 기본 기능
1. Add Music
마스터리스트에 곡을 추가한다.

2. Delete Music
곡의 id를 입력하여 마스터리스트에서 해당곡을 삭제한다.

3. Replace
마스터리스트의 곡을 변경한다.

4. Search ID
id를 입력하여 해당하는 곡을 출력한다.

5. Print all on screen
마스터리스트의 모든 아이템을 출력한다.

6. Make empty list
마스터리스트를 비운다.


7. Get from file
파일로부터 마스터리스트에 곡정보를 가져온다.

8. Put to file
마스터리스트의 정보를 파일에 기록한다.

9. Search by singer
싱어리스트에서 가수이름을 입력하여 해당 가수가 있는지 검색한다.

10. Search by genre
장르를 입력하면 해당하는 장르의 곡들이 마스터리스트에서 탐색되어 출력된다.

### PlayList 기능
11. Play Music
곡을 한 곡씩 플레이한다.

12. Play PlayList
플레이리스트에 있는 곡을 출력한다.
 - 일반재생 : 플레이리스트의 곡을 들어간 순서대로 플레이한다.
 - 셔플재생 : 플레이리스트의 곡을 랜덤 셔플하여 플레이한다.

13. Show PlayList
플레이리스트를 출력한다.


14. Delete PlayList
플레이리스트에서 원하는 곡을 삭제한다.

### Singer List 기능
15. Add Singer
싱어리스트에 가수를 추가한다.

16. Add Song
가수를 검색하고 해당하는 가수가 있으면 가수의 곡 목록에 곡을 추가한다.
 - 직접추가 : 직접 곡을 추가하고 마스터리스트에도 곡이 추가 된다.
 - 기존곡 추가 : 기존의 마스터리스트에 있는 곡을 추가한다.

17. Delete Song
가수를 검색하고 그 가수의 곡 목록에서 원하는 곡을 삭제한다.

18. Show Singer List
싱어리스트에 있는 가수를 전부 보여준다.






### FolderList 기능
19. Folder List
폴더 목록을 보여준다
 - Create Folder : 폴더를 생성한다.
 - Delete Folder : 폴더를 삭제한다.
 - Rename Folder : 폴더의 이름을 변경한다.
 - Access Folder : 폴더에 접근한다.

### * Access Folder 기능
- Add Song : 마스터리스트로부터 곡을 폴더에 추가한다.
- Delete Song : 폴더에서 원하는 곡을 삭제한다.
- Add to PlayList : 
  - 전체 추가 : 폴더내 모든 곡을 플레이리스트에 추가시킨다.
  - 개별 추가 : 폴더안에 있는 곡중 원하는 곡을 플레이리스트에 추가시킨다.
 
### System 기능
20. Recommend Music
장르를 입력받아 해당하는 장르의 곡을 랜덤으로 추천해준다.
(단, 마스터리스트에 해당 장르의 곡이 1곡이라도 있어야 한다.)



## 실행 이미지

![0](https://user-images.githubusercontent.com/55576129/115741556-d3f98b00-a3ca-11eb-8c29-6114ad924a98.png)
![1](https://user-images.githubusercontent.com/55576129/115741571-d78d1200-a3ca-11eb-89b1-9ce291da195c.png)
![2](https://user-images.githubusercontent.com/55576129/115741579-d956d580-a3ca-11eb-94ec-a82facdc0ba3.png)
![3](https://user-images.githubusercontent.com/55576129/115741586-db209900-a3ca-11eb-91f9-3f8555c78927.png)
![4](https://user-images.githubusercontent.com/55576129/115741600-de1b8980-a3ca-11eb-91ac-a7ef090d84dd.png)
![5](https://user-images.githubusercontent.com/55576129/115741618-e2e03d80-a3ca-11eb-90a1-cd88a4205376.png)
![6](https://user-images.githubusercontent.com/55576129/115741634-e4aa0100-a3ca-11eb-952e-f15bd59d1517.png)
![7](https://user-images.githubusercontent.com/55576129/115741667-e8d61e80-a3ca-11eb-8c13-3cc241002743.png)
![8](https://user-images.githubusercontent.com/55576129/115741676-eb387880-a3ca-11eb-955f-30fff99c958f.png)
![9](https://user-images.githubusercontent.com/55576129/115741683-ebd10f00-a3ca-11eb-9e7a-3367311025d0.png)
![10](https://user-images.githubusercontent.com/55576129/115741690-ed023c00-a3ca-11eb-8999-3db9552ec873.png)
![11](https://user-images.githubusercontent.com/55576129/115741691-ee336900-a3ca-11eb-8840-1b939a13d31b.png)
![12](https://user-images.githubusercontent.com/55576129/115741703-effd2c80-a3ca-11eb-8c37-28cfb4451d13.png)
![13](https://user-images.githubusercontent.com/55576129/115741710-f12e5980-a3ca-11eb-9927-a6ca62cd62c3.png)
![14](https://user-images.githubusercontent.com/55576129/115741719-f25f8680-a3ca-11eb-8ee8-fe39c0107420.png)
![15](https://user-images.githubusercontent.com/55576129/115741724-f390b380-a3ca-11eb-9bab-f2e4df4eb8db.png)
![16](https://user-images.githubusercontent.com/55576129/115741728-f55a7700-a3ca-11eb-90ba-5886dbb3d4ce.png)
![17](https://user-images.githubusercontent.com/55576129/115741734-f7243a80-a3ca-11eb-9729-6603ff2506fc.png)





