    #define MAX 1000001
    #include <bits/stdc++.h>
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    #include<stdio.h>
    #include <stdint.h>
    #include <unistd.h>
    using namespace std;
    class FastInput {
        public:
            FastInput() {
                            m_dataOffset = 0;
                            m_dataSize = 0;
                            m_v = 0x80000000;
                    }
                    uint32_t ReadNext() {
                            if (m_dataOffset == m_dataSize) {
                                    int r = read(0, m_buffer, sizeof(m_buffer));
                                    if (r <= 0) return m_v;
                                    m_dataOffset = 0;
                                    m_dataSize = 0;
                                    int i = 0;
                                    if (m_buffer[0] < '0') {
                                            if (m_v != 0x80000000) {
                                                    m_data[m_dataSize++] = m_v;
                                                    m_v = 0x80000000;
                                            }
                                            for (; (i < r) && (m_buffer[i] < '0'); ++i);
                                    }
                                    for (; i < r;) {
                                            if (m_buffer[i] >= '0') {
                                                    m_v = m_v * 10 + m_buffer[i] - 48;
                                                    ++i;
                                            } else {
                                                    m_data[m_dataSize++] = m_v;
                                                    m_v = 0x80000000;
                                                    for (i = i + 1; (i < r) && (m_buffer[i] < '0'); ++i);
                                            }
                                    }
                            }
                            return m_data[m_dataOffset++];
                    }
            public:
                    uint8_t m_buffer[32768];
                    uint32_t m_data[16384];
                    size_t m_dataOffset, m_dataSize;
                    uint32_t m_v;
    };
    class FastOutput {
            public:
                    FastOutput() {
                            m_dataOffset = 0;
                    }
                    ~FastOutput() {
                    }
                    void Flush() {
                            if (m_dataOffset) {
                                    if (write(1, m_data, m_dataOffset));
                                    m_dataOffset = 0;
                            }
                    }
                    void PrintUint(uint32_t v, char d) {
                            if (m_dataOffset + 11 > sizeof(m_data)) Flush();
                            if (v < 100000) {
                                    if (v < 1000) {
                                            if (v < 10) {
                                                    m_data[m_dataOffset + 0] = v + 48;
                                                    m_dataOffset += 1;
                                            } else if (v < 100) {
                                                    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
                                                    m_data[m_dataOffset + 0] = v + 48;
                                                    m_dataOffset += 2;
                                            } else {
                                                    m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
                                                    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
                                                    m_data[m_dataOffset + 0] = v + 48;
                                                    m_dataOffset += 3;
                                            }
                                    } else {
                                            if (v < 10000) {
                                                    m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 0] = v + 48;
     
                                                    m_dataOffset += 4;
     
                                            } else {
     
                                                    m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 0] = v + 48;
     
                                                    m_dataOffset += 5;
     
                                            }
     
                                    }
     
                            } else {
     
                                    if (v < 100000000) {
     
                                            if (v < 1000000) {
     
                                                    m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 0] = v + 48;
     
                                                    m_dataOffset += 6;
     
                                            } else if (v < 10000000) {
     
                                                    m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 0] = v + 48;
     
                                                    m_dataOffset += 7;
     
                                            } else {
     
                                                    m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 0] = v + 48;
     
                                                    m_dataOffset += 8;
     
                                            }
     
                                    } else {
     
                                            if (v < 1000000000) {
     
                                                    m_data[m_dataOffset + 8] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 0] = v + 48;
     
                                                    m_dataOffset += 9;
     
                                            } else {
     
                                                    m_data[m_dataOffset + 9] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 8] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
     
                                                    m_data[m_dataOffset + 0] = v + 48;
     
                                                    m_dataOffset += 10;
     
                                            }
     
                                    }
     
                            }
     
                            m_data[m_dataOffset++] = d;
     
                    }
     
                    void PrintChar(char d) {
     
                            if (m_dataOffset + 1 > sizeof(m_data)) Flush();
     
                            m_data[m_dataOffset++] = d;
     
                    }
     
                    void ReplaceChar(int offset, char d) {
     
                            m_data[m_dataOffset + offset] = d;
     
                    }
     
     
     
            public:
     
                    uint8_t m_data[32768];
     
                    size_t m_dataOffset;
     
    };
     
     
     
    FastInput fi;
     
    FastOutput fo;
    class BinaryMinHeap {
    private:
          int *data,*index;
          int heapSize;
          int arraySize;
     
          int getLeftChildIndex(int nodeIndex) {
                return 2 * nodeIndex + 1;
          }
     
          int getRightChildIndex(int nodeIndex) {
                return 2 * nodeIndex + 2;
          }
     
          int getParentIndex(int nodeIndex) {
                return (nodeIndex - 1) / 2;
          }
     
    public:
          BinaryMinHeap(int size) {
                data = new int[size];
                index = new int[size];
                heapSize = 0;
                arraySize = size;
          }    
          int hs()
          {
              return (heapSize);
          }
          void prr(long long T[])
          {
              for(int hh=0;hh<heapSize;hh++)
              {
                  cout<<data[hh]<<" "<<index[hh]<<" "<<T[index[hh]]<<endl;
              }
          }
          int getMinimum() {
                if (!isEmpty())
                      return data[0];
          }
          int getind(){
              return index[0];
          }
     
          bool isEmpty() {
                return (heapSize == 0);
          }
     
          void siftDown(int nodeIndex) {
          int leftChildIndex, rightChildIndex, minIndex, tmp;
          leftChildIndex = getLeftChildIndex(nodeIndex);
          rightChildIndex = getRightChildIndex(nodeIndex);
          if (rightChildIndex >= heapSize) {
                if (leftChildIndex >= heapSize)
                      return;
                else
                      minIndex = leftChildIndex;
          } else {
                if (data[leftChildIndex] >= data[rightChildIndex])
                      minIndex = leftChildIndex;
                else
                      minIndex = rightChildIndex;
          }
          if (data[nodeIndex] < data[minIndex]) {
                tmp = data[minIndex];
                data[minIndex] = data[nodeIndex];
                data[nodeIndex] = tmp;
                tmp = index[minIndex];
                index[minIndex] = index[nodeIndex];
                index[nodeIndex] = tmp;
                siftDown(minIndex);
          }
    }
     
    void removeMin() {
          if (!isEmpty()){
                data[0] = data[heapSize - 1];
                index[0] = index[heapSize -1];
                heapSize--;
                if (heapSize > 0)
                      siftDown(0);
          }
    }
     void siftUp(int nodeIndex) {
          int parentIndex, tmp;
          if (nodeIndex != 0) {
                parentIndex = getParentIndex(nodeIndex);
                if (data[parentIndex] < data[nodeIndex]) {
                      tmp = data[parentIndex];
                      data[parentIndex] = data[nodeIndex];
                      data[nodeIndex] = tmp;
                tmp = index[parentIndex];
                index[parentIndex] = index[nodeIndex];
                index[nodeIndex] = tmp;
                      siftUp(parentIndex);
                }
          }
    }
     
    void insert(int value,int valu2) {
          if (heapSize != arraySize){
                heapSize++;
                data[heapSize - 1] = value;
                index[heapSize -1 ]= valu2;
                siftUp(heapSize - 1);
          }
    }
     
    };
     
    int main() {
        
     
    int n,q,i=0,t,k,d;
     t=fi.ReadNext();
    while(t--)
    {   
        n=fi.ReadNext();
        d=fi.ReadNext();
        int j,nod=d;
        BinaryMinHeap a(100007);
        long long aa=0,bb=0;
        long long T[n],D[n],S[n];
        vector < vector <int> > dd(d+1,vector <int> (0,0));
        f(i,n)
        {   D[i]=fi.ReadNext();
            dd[D[i]].pb(i);
            T[i]=fi.ReadNext();
            S[i]=fi.ReadNext();
            bb+=T[i]*S[i];
        }
        /*
        a.insert(11,0);
        a.insert(10,0);
        a.insert(8,0);
        a.insert(2,0);
        a.insert(9,0);
        a.insert(6,0);
        while(!a.isEmpty()){
            
            a.prr();cout<<endl;
            a.removeMin();
        }
            a.prr();cout<<endl;
          */  
        
        for(i=1;i<d+1;i++)
        {
            int y= dd[i].size();
            f(j,y)
            {   
                a.insert((int)S[dd[i][j]],dd[i][j]);
            }
            
            
                    if(!a.isEmpty()){
                if(T[a.getind()]==0){
                a.removeMin();    
                }
                if(!a.isEmpty()){
                    aa+=a.getMinimum();
                    T[a.getind()]--;
                    
                if(T[a.getind()]==0){
                a.removeMin();    }
                }
            }
                    
           //a.prr(T);cout<<aa<<endl<<endl;
        }
        printf("%lld\n",bb-aa);
    }
    	return 0;
    }    