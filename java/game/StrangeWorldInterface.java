
public interface StrangeWorldInterface {
	/**
	 * Metoda ustawia rozmiar planszy do gry.
	 * 
	 * @param size rozmiar planszy. Dozwolone indeksy od 0 do size-1.
	 */
	public void setSize(int size);

	/**
	 * Metoda próbuje dodać na pozycji row/col nowy blok. W zależności od aktualnego
	 * stanu oraz właściwości bloku, blok jest lub nie jest dodawany. Dodanie bloku
	 * powoduje zwrócenie przez metodę prawdy. Jeśli blok zostanie dodany konieczne
	 * jest uwzględnienie jego własności - może się okazać, że dodany blok
	 * natychmiast doświadczy grawitacji i spadnie poniżej wiersza, w którym został
	 * dodany, a nawet wypadnie poza planszę.
	 * 
	 * @param row   wiersz, w którym następuje próba dodania bloku.
	 * @param col   kolumna, w której następuje próba dodania bloku.
	 * @param block dodawany blok
	 * @return true - blok został dodany na planszę, wartość zwracana nawet jeśli
	 *         blok w wyniku działania grawitacji wypadnie poza planszę, false -
	 *         blok nie został dodany.
	 */
	public boolean tryAdd(int row, int col, PhysicsInterface block);

	/**
	 * Metoda zleca usunięcie bloku na pozycji row/col. Jeśli blok zostanie usunięty
	 * referencja do usuwanego bloku zostaje zwrócona. Po usunięcie bloku należy
	 * sprawdzić konsekwencje tego działania na pozostałe w pobliżu bloki (czyli np.
	 * ich upadek).
	 * 
	 * @param row wiersz, w którym blok ma być usunięty
	 * @param col kolumna, w której blok ma być usunięty
	 * @return obiekt, który znajdował się na pozycji row/col. Jeśli na wskazanej
	 *         pozycji nie było obiektu metoda zwraca NULL.
	 */
	public PhysicsInterface delAndGet(int row, int col);

	/**
	 * Metoda zwraca obiekt znajdujący się na planszy na pozycji row/col.
	 * 
	 * @param row wiersz
	 * @param col kolumna
	 * @return obiektu na pozycji row/col
	 */
	public PhysicsInterface get(int row, int col);
}
