


public abstract class Decoder {
	static int times = 0;
	static char[] tab;
	static String bufer="aa";
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
		String helper = input;
		helper = helper.replace(" ","");
		

		char[] ch = new char[input.length()]; 
		char[] dh = new char[input.length()];
  
        // Copy character by character into array 

		if(times != 0){
			for(int i3 = times; i3 > 0; i3--){
				bufer = bufer + helper;
			}
			times = 0;
		}

        for (int i2 = 0; i2 < helper.length(); i2++) { 
			if(helper.charAt(i2)=='0') {

				int p = i2+1;
				if(helper.charAt(p)=='0') {

					reset();
					return;

				}
				else{
					int j = helper.charAt(p)-'0';


					StringBuilder sb = new StringBuilder(helper);
   					sb.deleteCharAt(p);
					sb.deleteCharAt(p-1);
					helper = sb.toString();
					
					times = j;


				}

				bufer = bufer + helper;


			}
        }



	}

	public static void main(String[] args) {
		System.out.println("lloo");
		decode("qw03");
		System.out.println("pr:"+bufer);
		decode("q");
		System.out.println("pr:"+bufer);
		
	}


}