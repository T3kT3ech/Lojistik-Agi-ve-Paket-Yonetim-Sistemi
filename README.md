# Lojistik Ağı ve Paket Yönetim Sistemi

Bu proje, kargo paketlerinin takibini ve şehirler arası lojistik ağının yönetimini simüle eden, C programlama dili ile geliştirilmiş bir terminal uygulamasıdır. Proje, veri yapıları kavramlarını pratik bir senaryoda birleştirmek amacıyla geliştirilmiş olup, **Graph (Çizge)** ve **Hash Table (Özet Tablosu)** veri yapılarını eş zamanlı olarak kullanır.

## 🚀 Proje Özellikleri

* **Dinamik Paket Yönetimi (Hash Table):** * Paketler, benzersiz ID'lerine göre Hash tablosuna eklenir ve sorgulanır.
    * Bölme (Modulo) tabanlı Hash Fonksiyonu kullanılmıştır (`hashFunctionA`).
    * Çakışma (Collision) durumları **Linear Probing** (Doğrusal Yoklama) yöntemi ile başarılı bir şekilde çözülmüştür.
* **Şehirler Arası Lojistik Ağı (Graph):**
    * Maksimum 20 şehre kadar destek veren dinamik bir ağ altyapısı kurulmuştur.
    * Şehirler arası bağlantılar (Edge) Adjacency List (Komşuluk Listesi) mantığı ile bellekte tutulur.
* **Ağ Taraması (BFS):**
    * Belirtilen bir başlangıç şehrinden itibaren tüm lojistik ağı **Breadth-First Search (Sığ Öncelikli Arama)** algoritması ile taranarak ekrana yazdırılır.
* **Güvenli ve Sağlam Girdi Kontrolü (Bug Önleme):**
    * Standart `scanf` hatalarını ve sonsuz döngü bug'larını önlemek amacıyla özel `guvenliSayiAl` ve `guvenliMetinAl` fonksiyonları yazılmıştır.
    * Kullanıcı harf veya geçersiz sembol girdiğinde program çökmez, belleği (`buffer`) temizleyerek doğru veri girişini bekler.

## 📂 Dosya Yapısı

Proje modüler bir yapıda tasarlanmıştır:

* `logistics.h`: Yapı (struct) tanımlarını, sabitleri (TABLE_SIZE) ve fonksiyon prototiplerini içeren başlık dosyası.
* `main_final_degerlendirme_odevi_4.c`: Ana menü döngüsünü ve kullanıcı arayüzünü barındıran kontrol dosyası.
* `hash_final_degerlendirme_odevi_4.c`: Hash tablosunun başlatılması, paket ekleme ve arama algoritmalarını içeren dosya.
* `graph_final_degerlendirme_odevi_4.c`: Graf veri yapısının oluşturulması, şehirlere bağlantı eklenmesi ve BFS tarama algoritmasının yer aldığı dosya.
