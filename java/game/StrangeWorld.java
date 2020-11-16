
class StrangeWorld implements StrangeWorldInterface
{

    PhysicsInterface map[][];






    public void setSize(int size){
        this.map = new PhysicsInterface[size][size];
    }

    public boolean tryAdd(int row, int col, PhysicsInterface block){
        if(this.map[row][col]==null){
        
            if(block.mustBeSupportedFromAnySideToBePlaced()==true){
                if(neighbour(row,col)==false){
                    return false;
                }else{
                    this.map[row][col] = block;
                    qfall(row,col);
                }
            } else {
                this.map[row][col] = block;
                qfall(row,col);
            }

        }else{
            return false;
        }
        return true;
    }

    public boolean qfall(int row, int col){
        if(this.map[row][col]!=null){

            if(this.map[row-1][col]==null){

                if(this.map[row][col].canFloatInTheAirWithoutSupport()==false){
                    if(neighbour(row,col)==false){
                        fall(row,col);
                        return true;
                    }
                } else if(this.map[row][col].willFallIfNotSupportedFromBelow()==true){
                    if(this.map[row-1][col]==null){
                        fall(row,col);
                        return true;
                    }
                } else {
                    return false;
                }
            }

        }
        return false;
    }

    public void fall(int row, int col){

        if(row==0){
            delAndGet(row,col);
        } else if(this.map[row-1][col]==null){
            this.map[row-1][col] = delAndGet(row,col);
            domino(row,col);
            fall(row-1,col);
        }
    }

    public void domino(int row, int col){
        if(qfall(row,col-1)){
        }else if(qfall(row,col+1)){
        }else if (qfall(row+1,col)){}
    }

    public boolean neighbour(int row, int col){
        if(this.map[row-1][col]!=null || this.map[row+1][col]!=null || this.map[row][col+1]!=null || this.map[row][col-1]!=null){
            return true;
        } else{
            return false;
        }
    }

    public PhysicsInterface delAndGet(int row, int col){
        PhysicsInterface h = this.map[row][col];
        this.map[row][col] = null;
        return h;
    }

    public PhysicsInterface get(int row, int col){
        if(this.map[row][col]!=null){
            return this.map[row][col];
        }else{
            return null;
        }
    }

}

