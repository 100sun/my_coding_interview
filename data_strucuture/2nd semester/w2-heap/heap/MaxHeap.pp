// 삽입 함수: 힙에 키값 key를 갖는 
// 새로운 요소를 삽입한다.
void insert( int key )
{
       // 새 노드 삽입할 마지막 인덱스 결정 [예제] 11
       if( isFull() ) return;	// 힙이 가득 찬 경우
       int i = ++size; 		// 힙 크기 1 증가, i=신규 삽입할 자리

       // 새 노드가 최대힙 성질을 만족하도록 UP UP !
       while( i!=1 				// i=1: 루트 노드
              && key>getParent(i).getKey()) {	// 부모보다 키값이 큰 동안 반복
                   node[i] = getParent(i);	// 부모를 자식 자리로 down
                   I /= 2;			// 한 레벨 위에서 다시 비교
        }
        node[i].setKey( key );	          // 최종 적합한 위치에 신규 키값 저장
}
