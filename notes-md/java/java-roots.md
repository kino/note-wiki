%title Java root objects

The so-called GC (Garbage Collector) roots are objects special for garbage collector. Garbage collector collects those objects that are not GC roots and are not accessible by references from GC roots.

There are several kinds of GC roots. One object can belong to more than one kind of root. The root kinds are:

* **Class** - class loaded by system class loader. Such classes can never be unloaded. They can hold objects via static fields. Please note that classes loaded by custom class loaders are not roots, unless corresponding instances of java.lang.Class happen to be roots of other kind(s).
* **Thread** - live thread
* **Stack Local** - local variable or parameter of Java method
* **JNI Local** - local variable or parameter of JNI method
* **JNI Global** - global JNI reference
* **Monitor Used** - objects used as a monitor for synchronization
* **Held by JVM** - objects held from garbage collection by JVM for its purposes. Actually the list of such objects depends on JVM implementation. Possible known cases are: the system class loader, a few important exception classes which the JVM knows about, a few pre-allocated objects for exception handling, and custom class loaders when they are in the process of loading classes. Unfortunately, JVM provides absolutely no additional detail for such objects. Thus it is up to the analyst to decide to which case a certain "Held by JVM" belongs.
