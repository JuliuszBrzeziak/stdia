
public interface ChomikInterface {
	/**
	 * Aby położyć na planszy obiekt musi on posiadać w najbliższym sąsiedztwie
	 * (prawo/lewo/góra/dół) inny blok. Uwaga zaraz po umieszczeniu blok może zacząć
	 * spadać a nawet wypaść poza plansze. Wynik metody odnosi się wyłącznie do
	 * samej możliwości położenia bloku na planszy.
	 * 
	 * @return true - blok może być umieszczony tylko w najbliższym sąsiedztwie
	 *         innego bloku, false - blok może być umieszczony w dowolnym miejscu
	 *         planszy.
	 */
	public boolean czytochomik(){
        System.out.print("no jakiś chomik");
        return true;
    }

	/**
	 * Blok może unosić się w powietrzu nie mając kontaktu z innymi blokami. W tym
	 * przypadku chodzi o istnienie dowolnego innego bloku sąsiadującego z danym z
	 * dowolnej strony (prawo/lewo/góra/dół).
	 * 
	 * @return true - blok, który nie ma sąsiada pozostaje na swoim miejscu. false -
	 *         blok, który nie ma sąsiada spada.
	 */
	public boolean canFloatInTheAirWithoutSupport();

	/**
	 * Blok spada jeśli poniżej niego nie znajduje się inny blok.
	 * 
	 * @return true - blok musi być podparty od dołu aby nie spadł. false - blok
	 *         niepodparty z dołu może unosić się w powietrzu.
	 */
	public boolean willFallIfNotSupportedFromBelow();
}
