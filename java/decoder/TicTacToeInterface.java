 
public interface TicTacToeInterface {
	/**
	 * Metoda pozwala na ustalenie rozmiaru kwadratowej planszy. Dla rozmiaru size
	 * dozwolone są numery wierszy i kolumn o wartościach od 0 do size -1 . Metoda
	 * uruchamiana przed rozgrywką.
	 * 
	 * @param size rozmiar planszy.
	 */
	public void setSize(int size);

	/**
	 * Metoda pozwala na umimeszczenie w pozycji o współrzędnych row i col znaku
	 * koła.
	 * 
	 * @param col kolumna
	 * @param row wiersz
	 */
	public void setO(int col, int row);

	public void setX(int col, int row);


	/**
	 * Metoda pozwala na umimeszczenie w pozycji o współrzędnych row i col znaku
	 * krzyżyka.
	 * 
	 * @param col kolumna
	 * @param row wiersz
	 */

	/**
	 * Metoda zwraca znak znajdujący się na wskazanej pozycji. Wynikiem może być
	 * tylko "" (pusty ciąg znaków), "O" - duże o lub "X" duży znak x. Jeśli
	 * wskazana za pomocą col i row pozycja nie zawiera znaku krzyżyka lub koła
	 * metoda zwraca pusty ciąg znaków. Jeśli wskazana za pomocą col i row pozycja
	 * nie istnieje na planszy zwracany jest pusty ciąg znaków.
	 * 
	 * @param col kolumna
	 * @param row wiersz
	 * @return informacja o zawartości danego położenia planszy.
	 */
	public String get(int col, int row);
}
