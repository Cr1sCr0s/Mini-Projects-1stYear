ITEA Room Setup Cost Calculator — HTML + JavaScript
====================================================

This project implements an interactive room setup order form for ITEA using HTML and JavaScript. It allows users to select room furnishings, apply delivery options, and dynamically calculate the total cost of the setup based on detailed pricing rules and business logic.

---

🧾 Key Features
----------------

- **Room Setup Cost Calculator** based on selected furniture and room size
- **Dynamic Bed Size Rules** depending on the selected room type
- **Discounted Table Pricing** based on quantity of table types selected
- **Room Size Multiplier** applied to total base cost
- **Optional Delivery Option** with conditional fields and validation
- **Order Summary** displayed using `alert()` upon successful submission

---

💸 Cost Calculation Logic
-------------------------

Final formula:
TOTAL = [(bed_size + cabinet + tables (with discount) + decorations) × room_size_multiplier] + delivery_fee


### Beds:
- Enabled/disabled dynamically based on selected room type
- Prices:
  - Single: P12,000
  - Double: P13,500
  - Queen: P16,000
  - King: P20,000

### Cabinets (no restrictions):
- Bookcase: P5,000
- Storage Shelf: P10,500
- Wall Shelf: P2,500

### Tables (with discount tiers):
- Desk: P7,000
- Bedside Table: P3,500
- Multifunctional Table: P10,000
- Dressing Table: P8,000

Discounts:
- 2 tables → 10% off
- 3 tables → 15% off
- 4 tables → 25% off

### Decorative Additions (no discounts):
- Mirror: P2,500
- Rug: P8,000
- Wall Accents: P1,000
- Clock: P500

### Room Size Multipliers:
- Small: ×1
- Medium: ×1.25
- Large: ×1.5
- Extra Large: ×2

### Delivery Options:
- Delivery: +P1,000
  - Requires valid address, date, and time
  - Delivery date must be **in the future**
  - Delivery time must be **between 9 AM and 6 PM**
- Pickup: P0
  - Disables delivery-related fields

---

🔐 Form Validations
-------------------

- **Required fields**: Name, Mobile, Email, Address (if delivery)
- **Mobile format**: Starts with `09`, 11 digits total
- **Email**: Must follow valid format
- **Delivery date**: Must be a future date
- **Delivery time**: Must be between 9:00 and 18:00

All validations are handled in JavaScript using event listeners and `input` checks.

---

🚚 Conditional Interactions
---------------------------

- Selecting **delivery** enables address, date, and time inputs
- Selecting **pickup** disables these and removes delivery fee
- Room type affects which bed sizes are enabled:
  - Bedroom: all enabled
  - Living Room / Office: all beds disabled (price = 0)
  - Children's Room: only Single/Double enabled

---

📋 Summary on Submit
---------------------

When the form is successfully submitted:
- The page is **not reloaded** (via `preventDefault()`)
- An `alert()` displays the full order summary, including:
  - Customer info
  - Room selections
  - Total cost

📌 Sample Code Snippet to Prevent Reload:
```html
<script>
document.getElementById("form").addEventListener("submit", function(e) {
  e.preventDefault();
  // calculation and alert logic here...
});
</script>