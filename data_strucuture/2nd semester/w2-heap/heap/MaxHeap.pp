// ���� �Լ�: ���� Ű�� key�� ���� 
// ���ο� ��Ҹ� �����Ѵ�.
void insert( int key )
{
       // �� ��� ������ ������ �ε��� ���� [����] 11
       if( isFull() ) return;	// ���� ���� �� ���
       int i = ++size; 		// �� ũ�� 1 ����, i=�ű� ������ �ڸ�

       // �� ��尡 �ִ��� ������ �����ϵ��� UP UP !
       while( i!=1 				// i=1: ��Ʈ ���
              && key>getParent(i).getKey()) {	// �θ𺸴� Ű���� ū ���� �ݺ�
                   node[i] = getParent(i);	// �θ� �ڽ� �ڸ��� down
                   I /= 2;			// �� ���� ������ �ٽ� ��
        }
        node[i].setKey( key );	          // ���� ������ ��ġ�� �ű� Ű�� ����
}