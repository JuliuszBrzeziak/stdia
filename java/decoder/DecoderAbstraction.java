
 abstract class DecoderAbstraction {
	/**
	 * Metoda pozwala na przekazanie ciągu znaków, który ma zostać odkodowany.
	 * Sposób odkodowywania znaków przedstawiony jest w opisie zadania.
	 *
	 * @see <a href="https://zti.if.uj.edu.pl/Piotr.Oramus/dydaktyka/Java/Zadania/">Strona WWW kursu</a>
	 * @param input ciąg do odkodowania
	 */
	public abstract void decode(String input);

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
	public abstract void reset();
}



public class Decoder extends DecoderAbstraction{

	public void decode(String input){
		system.out.println("hello");
	}

	public static void main(String[] args) {
		system.out.println("lloo");
	}


}