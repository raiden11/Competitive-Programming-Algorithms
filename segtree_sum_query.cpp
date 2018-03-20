

void create_tree(int low,int high,int pos)
{
    if(low==high)
    {
        seg[pos]=a[low];
        return;
    }
    int mid=(low+high)/2;
    create_tree(low,mid,2*pos+1);
    create_tree(mid+1,high,2*pos+2);
    seg[pos]=seg[2*pos+1]+seg[2*pos+2];
}

int rmq(int low,int high,int pos,int x,int y)
{
    if(x>high||y<low)
        return 0;
    else if(x<=low&&y>=high)
        return seg[pos];
    int mid=(low+high)/2;
    return rmq(low,mid,2*pos+1,x,y)+rmq(mid+1,high,2*pos+2,x,y);
}

void update(int low,int high,int val,int pla,int pos)
{
    if(low==high)
    {
        seg[pos]=val;
        return ;
    }
    int mid=(low+high)/2;
    if(pla<=mid)
    {
        update(low,mid,val,pla,2*pos+1);
        seg[pos]=seg[2*pos+1]+seg[2*pos+2];
    }
    else
    {
        update(mid+1,high,val,pla,2*pos+2);
        seg[pos]=seg[2*pos+1]+seg[2*pos+2];
    }
}


