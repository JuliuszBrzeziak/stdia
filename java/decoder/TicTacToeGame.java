
//JULIUSZ BRZEZIAK




class TicTacToeGame implements TicTacToeInterface{

	int size = 0;
	String tour = " ";
	String[][] tab  = new String[1][1];


	@Override

	public String get(int col, int row){
		if(col >= this.size || row >= this.size||this.tab[col][row]==null){
			return "";
		}
		return this.tab[col][row];
	}
	
	public void setX(int col, int row){
		if((this.tour == "X" || this.tour == " ") && this.size != 0  && col < this.size && row < this.size && this.tab[col][row]==null){
		this.tab[col][row] = "X";
		this.tour = "O";
			
		}
	}
	public void setO(int col, int row){
		if((this.tour == "O" || this.tour == " ") && this.size != 0  && col < this.size && row < this.size && this.tab[col][row]==null){
			this.tab[col][row] = "O";
			this.tour = "X";

			
		}
	}
	public void setSize(int size){
		if(this.size < size){
			this.size = size;
			this.tab = new String[size][size];

		}
	}

}