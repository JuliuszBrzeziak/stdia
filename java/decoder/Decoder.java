


public abstract class Decoder {
	static int times = 0;
	static String bufer="";
	static String pod="";
	static boolean pd = false;
	static boolean z = false;



	/**
	 * Metoda pozwala na przekazanie ciągu znaków, który ma zostać odkodowany.
	 * Sposób odkodowywania znaków przedstawiony jest w opisie zadania.
	 *
	 * @see <a href="https://zti.if.uj.edu.pl/Piotr.Oramus/dydaktyka/Java/Zadania/">Strona WWW kursu</a>
	 * @param input ciąg do odkodowania
	 */
	//public abstract void decode(String input);

	/**
	 * Metoda umożliwia pobranie ciągu znaków znajdującego się w buforze. Działanie
	 * metody nigdy nie może doprowadzić do pojawienia się wyniku null. Gdy brak
	 * znaków w buforze metoda zwraca pusty ciąg ("").
	 * 
	 * @return aktualny stan bufora
	 */
	public abstract String getBuffer();

	/**
	 * Metoda resetuje dekoder do stanu początkowego. Wszystkie znaki w buforze są
	 * kasowane. Informacje przekazane do chwili wykonania tej metody mają zostać
	 * zapomniane (np. informacja o tym, że nadawany jest podciąg).
	 */
	public static void reset(){
		times = 0;
		bufer = "";
	}





	public static void decode(String input){
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
				else if(helper.charAt(i+1)=='1' && pd == false){
					pd = true;
					i=i+1;
				}
				//01 true
				else if(helper.charAt(i+1)=='1' && pd == true){
					pd = false;
					for(int i3 = times; i3 > 0; i3--){
						bufer = bufer + pod;
					}
					times = 0;
					pod = "";
					i=i+1;
				}

				else if(times != 0 && pd == false){
					int n = i;
					n = n-1;
					
				}
				//0x
				else {
					times = helper.charAt(i+1)-'0';
					i=i+1;
				}
				
			}
			//01
			else if(pd==true){
				pod = pod + helper.charAt(i);
			}

			else{
				if(times != 0 && pd==false){
					for(int i3 = times; i3 > 0; i3--){
						bufer = bufer + helper.charAt(i);
					}
					times = 0;
				}
				bufer = bufer + helper.charAt(i);
			}

		}

	}


	public static void main(String[] args) {
		String a="123";
		System.out.println(a.length());
		decode("qw003abc01d");
		System.out.println("pr:"+bufer);
		decode("zxcxv");
		System.out.println("pr:"+bufer);
		decode("01");
		System.out.println("pr:"+bufer);

		
	}


}