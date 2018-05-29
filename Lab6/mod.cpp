for(int i=1; i <= 5; i++)
    {
        std::cout<<"Generating random numbers!!!\n";
        srand(i);
        nNum = 50000;
        min5Heap heap1 = min5Heap(nNum);
        /*for(int j=0; j<nNum; j++)
        {
            iNum = rand() % 4*nNum + 1;
            numArray1[j] = iNum;
        }*/
        
        timer.start();
            for(int k=0; k<nNum; k++)
            {
                heap1.insert(rand() % 4*nNum + 1);
            }
        timeCount = timer.stop();
        
        std::cout<<"Time the min5Heap Build!!!\n";
        heapBuildTimeArray1[i-1] = timeCount;

        timer.start();
            for(int k=0; k<nNum; k++)
            {
                BST1.insert(rand() % 4*nNum + 1);
            }
        timeCount = timer.stop();

        std::cout<<"Time the BST Build!!!\n";
        BSTBuildTimeArray1[i-1] = timeCount;

        timer.start();
            for(int n=0; n<nNum/10; n++)
            {
                zNum = rand()/nNum;
                if((0 <= zNum)&&(zNum < 0.25))
                {
                    heap1.deletemin();
                }
                else if((0.25 <= zNum)&&(zNum < 0.5))
                {
                    heap1.deletemax();
                }
                else if((0.5 <= zNum)&&(zNum < 0.75))
                {
                    iNum = rand()%4*nNum+1;
                    heap1.remove(iNum);
                }
                else
                {
                    iNum = rand()%4*nNum+1;
                    heap1.insert(iNum);
                }
            }
        timeCount = timer.stop();

        std::cout<<"Time the min5Heap Operations!!!\n";
        heapOperationTimeArray1[i-1] = timeCount;

        timer.start();
            for(int n=0; n<nNum/10; n++)
            {
                zNum = rand()/nNum;
                //std::cout<<"This is the number I am generating:"<<zNum<<"\n";
                if((0 <= zNum)&&(zNum < 0.25))
                {
                    BST1.deletemin();
                }
                else if((0.25 <= zNum)&&(zNum < 0.5))
                {
                    BST1.deletemax();
                }
                else if((0.5 <= zNum)&&(zNum < 0.75))
                {
                    iNum = rand()%4*nNum+1;
                    heap1.remove(iNum);
                }
                else
                {
                    iNum = rand()%4*nNum+1;
                    BST1.insert(iNum);
                }
            }
        timeCount = timer.stop();

        std::cout<<"Time the BST Operations!!!\n";
        BSTOperationTimeArray1[i-1] = timeCount;

        if(i < 5)
        {
            if(!heap1.isEmpty())
            {
                heap1.resetHeap();
            }
            if(!BST1.isEmpty())
            {
                //BST1.deletemin();
                BST1.~BinarySearchTree();
            }
        }
        
    }
    std::cout<<"Calculating averages!!!\n";
    heapBuildTimeArray1[5] = timeAverage(5, heapBuildTimeArray1);
    BSTBuildTimeArray1[5] = timeAverage(5, BSTBuildTimeArray1);

    std::cout<<"Print the time results!!!\n";

    for(int l=0; l<6; l++)
    {
        if(l < 5)
        {
            std::cout<<"time to build min5Heap with "<<nNum<<" numbers: "; timer.printTime(heapBuildTimeArray1[l]); std::cout<< " time to build BST with "<<nNum<<" numbers: "; timer.printTime(BSTBuildTimeArray1[l]); std::cout<< "\n";
        }
        else
        {
            std::cout<<"time to build average min5Heap with "<<nNum<<" numbers: "; timer.printTime(heapBuildTimeArray1[l]); std::cout<< " time to build average BST with "<<nNum<<" numbers: "; timer.printTime(BSTBuildTimeArray1[l]); std::cout<< "\n";
        }
    }
    for(int m=0; m<6; m++)
    {
        if(m < 5)
        {
            std::cout<<"time to Operate min5Heap with "<<nNum<<" numbers: "; timer.printTime(heapOperationTimeArray1[m]); std::cout<< " time to Operate BST with "<<nNum<<" numbers: "; timer.printTime(BSTOperationTimeArray1[m]); std::cout<< "\n";
        }
        else
        {
            std::cout<<"time to Operate average min5Heap with "<<nNum<<" numbers: "; timer.printTime(heapOperationTimeArray1[m]); std::cout<< " time to Operate average BST with "<<nNum<<" numbers: "; timer.printTime(BSTOperationTimeArray1[m]); std::cout<< "\n";
        }
    }