# Πρότυπο Σχεδίασης: Mediator

- Το συγκεκριμένο πρότυπο ορίζει ένα αντικείμενο (mediator) που περικλείει τον τρόπο με τον οποίο αλληλεπιδρά μια ομάδα αντικειμένων.
- Πρακτικά, τα αντικείμενα της ομάδας δεν επικοινωνούν απευθείας μεταξύ τους, αλλά μέσω του αντικειμένου/mediator.
- Η εφαρμογή του προτύπου συμβάλλει στη μείωση των εξαρτήσεων μεταξύ των αντικειμένων.
- Μειονεκτήματα: ενδεχομένως προκύψει κάποια super κλάση.


## Γενική περιγραφή Mediator
Η γενική αρχή της σχεδίασης θα μπορούσε να αποτυπωθεί ως εξής:

<kbd>![Wikipedia: mediator pattern](./img/cd_mediator01.png)</kbd>
*Η εικόνα είναι εμπνευσμένη από την ομώνυμη ταινία γουέστερν: [The_Good,_the_Bad_and_the_Ugly](https://en.wikipedia.org/wiki/The_Good,_the_Bad_and_the_Ugly).*





## Παράδειγμα κώδικα

- [ ] [Έλεγχος εναέριας κυκλοφορίας](./source_code/airTrafficControl.cpp) (C++)

## Ενδεικτικές πηγές για περαιτέρω μελέτη:
- [ ] [Design patterns: C++ examples on Github](https://github.com/JakubVojvoda/design-patterns-cpp/tree/master)
- [ ] [Design patterns: elements of reusable object-oriented software](http://faculty.chas.uni.edu/~wallingf/teaching/062/sessions/support/pattern-examples.pdf)
- [ ] [Evaluation of design pattern alternatives in Java](https://onlinelibrary.wiley.com/doi/pdf/10.1002/spe.3061)
- [ ] [Class Diagram - StarUML documentation](https://docs.staruml.io/working-with-uml-diagrams/class-diagram)
- [ ] [Wikipedia: mediator pattern](https://en.wikipedia.org/wiki/Mediator_pattern)
