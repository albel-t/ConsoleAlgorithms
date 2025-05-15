




#include "laba_7.h"












void l7task1()
{
    int a, b;
    {
        cout << "[graph]:" * data_color << mcl::endl;
        graph_unweighted mewGraph(10);
        mewGraph.print();
        cout << "[graph_unweighted] enter dots from and to:" << mcl::endl;
        std::cin >> a >> b;
        mewGraph.Find(a, b);

    }
    {
        cout << "[graph]:" * data_color << mcl::endl;
        graph_weighted mewGraph(10);
        mewGraph.print();
        cout << "[graph_weighted] enter dots from and to:" << mcl::endl;
        std::cin >> a >> b;
        mewGraph.Find(a, b);


    }

}
























