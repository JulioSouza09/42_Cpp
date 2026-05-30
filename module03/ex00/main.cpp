/*
  given:
    default-constructed ClapTrap (no arguments)
  when:
    default constructor runs
  then:
    - name is "Cl4pTr4p"
    - hitPoints is 10
    - energyPoints is 10
    - attackDamage is 0
    - a creation message including the name is printed to stdout

  given:
    ClapTrap constructed with a name (e.g. `ClapTrap("Name")`)
  when:
    parameterized constructor runs
  then:
    - name is the provided string
    - hitPoints is 10
    - energyPoints is 10
    - attackDamage is 0
    - a creation message including the provided name is printed to stdout

  given:
    an existing ClapTrap instance
  when:
    destructor runs
  then:
    - a destruction message including the instance name is printed to stdout
*/