



public class Decoder {
	int times = 0;
  	String bufer="";
  	String pod="";
  	boolean pd = false;

	int c = 3;

	public void f(){
		System.out.println(c);
		
	}



	public  String getBuffer(){
		if(this.bufer==null){
			return "";
		}

		else{
			return this.bufer;
		}
	}

	/**
	 * Metoda resetuje dekoder do stanu początkowego. Wszystkie znaki w buforze są
	 * kasowane. Informacje przekazane do chwili wykonania tej metody mają zostać
	 * zapomniane (np. informacja o tym, że nadawany jest podciąg).
	 */
	public  void reset(){
		this.times = 0;
		this.bufer = "";
	}





	public  void decode(String input){
		getBuffer();
		StringBuilder helper = new StringBuilder(input);
		StringBuilder helperpod = new StringBuilder("");


		for(int i = 0;i<helper.length();i++){

			if(helper.charAt(i)=='0'){

				//00
				if(helper.charAt(i+1)=='0'){
					reset();
					return;
				}
				 //01 false
				else if(helper.charAt(i+1)=='1' && this.pd == false){
					this.pd = true;
					i=i+1;
				}
				//01 true
				else if(helper.charAt(i+1)=='1' && this.pd == true){
					this.pd = false;
					for(int i3 = this.times; i3 > 0; i3--){
						this.bufer = this.bufer + this.pod;
					}
					this.times = 0;
					this.pod = "";
					i=i+1;
				}

				else if(this.times != 0 && this.pd == false){
					int n = i;
					n = n-1;
					
				}
				//0x
				else {
					this.times = helper.charAt(i+1)-'0';
					i=i+1;
				}
				
			}
			//01
			else if(this.pd==true){
				this.pod = this.pod + helper.charAt(i);
			}

			else{
				if(this.times != 0 && this.pd==false){
					for(int i3 = this.times; i3 > 0; i3--){
						this.bufer = this.bufer + helper.charAt(i);
					}
					this.times = 0;
				}
				this.bufer = this.bufer + helper.charAt(i);
			}

		}

	}


	public static void main(String[] args) {
		String a="123";
		System.out.println(a.length());
		Decoder dec = new Decoder();
		dec.f();
		dec.decode("qw03abc01d");
		System.out.println("pr:"+dec.bufer);
		dec.decode("zxcxv");
		System.out.println("pr:"+dec.bufer);
		dec.decode("01");
		System.out.println("pr:"+dec.bufer);

		
	}


}