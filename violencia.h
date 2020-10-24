#pragma once

namespace Lab4KarlBech1015920 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Resumen de violencia
	/// </summary>
	public ref class violencia : public System::Windows::Forms::Form
	{
	private:
		
	private: System::Windows::Forms::OpenFileDialog^ ofd_txt;




		   

	public:
		violencia(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~violencia()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	protected:

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(316, 384);
			this->dataGridView1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(279, 392);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &violencia::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(394, 36);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Bubblesort";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &violencia::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(394, 89);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Mergesort";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(394, 138);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Quicksort";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// violencia
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(612, 427);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"violencia";
			this->Text = L"violencia";
			this->Load += gcnew System::EventHandler(this, &violencia::violencia_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		array<String^, 2>^ matriz = gcnew array<String^, 2>(3, 241);
	private: void ReestablecerMatriz() {
		dataGridView1->Rows->Clear();
		dataGridView1->Columns->Clear();
		dataGridView1->ColumnHeadersVisible = false;
		dataGridView1->RowHeadersVisible = false;
	};

	private: void Llenar() {
		


			//Se utiliza el objeto File para leer el archivo solo cuando el FileName es correcto
			//Importante haber llamado al namespace System::IO antes de usar File
			array<String^>^ archivoLineas = File::ReadAllLines(openFileDialog1->FileName);

			if (archivoLineas->Length > 0) {

				//Obtiene la cantidad de elementos de la primer linea y ese toma como cantidad de columnas
				array<String^>^ archivoColumna = archivoLineas[0]->Split(';');
				if (archivoColumna->Length > 0) {
					int cantidadColumnas = archivoColumna->Length;
					


				


					//Agrega las columnas
					for (int i = 0; i < cantidadColumnas; i++) {
						//Crea una columna
						DataGridViewColumn^ nuevacolumna = gcnew DataGridViewColumn();
						nuevacolumna->Width = 100;
						//Le agrega el tipo de columna que será
						DataGridViewCell^ cellTemplate = gcnew DataGridViewTextBoxCell();
						nuevacolumna->CellTemplate = cellTemplate;
						//Inserta la columna
						dataGridView1->Columns->Add(nuevacolumna);
					}

					//Agrega las filas de manera dinámica
					for (int i = 0; i < archivoLineas->Length; i++) {
						dataGridView1->Rows->Add();
					}

					//Llena el DatagridView
					for (int i = 0; i < archivoLineas->Length; i++) {
						array<String^>^ fila = archivoLineas[i]->Split(';');
						int j = 0;
						matriz[j, i] = fila[j];

					
						while ((j < cantidadColumnas) && (j < fila->Length)) {
							dataGridView1->Rows[i]->Cells[j]->Value = fila[j];
							j++;
						}
					}
				}

			
		}

		
		
	};


		
	private: System::Void violencia_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	public: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		//Se agregan los filtros al OpenFileDialog
		openFileDialog1->Filter = "Archivos separados por coma (csv) | *.csv";
		openFileDialog1->FileName = "";
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			ReestablecerMatriz(); //Se elimina cualquier contenido de la matriz
			Llenar();
		}
		else {
			// Si no se selecciona correctamente un elemento entonces falla
			MessageBox::Show("No se seleccionó ningún archivo"
				, "Archivo no seleccionado"
				, MessageBoxButtons::OK
				, MessageBoxIcon::Exclamation);
		}

		
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ aux1;
		String^ aux2;
		int aux, i, j;
		for (i = 1; i < 241 - 1; i++) {

			// Last i elements are already in place
			for (j = 1; j < 241; j++) {
				if (Convert::ToInt32(matriz[2, i]) > Convert::ToInt32(matriz[2, j])) {
					aux = Convert::ToInt32(matriz[2, i]);
					matriz[2, i] = matriz[2, j];
					matriz[2, j] = Convert::ToString(aux);

					aux1 = matriz[1, i];
					matriz[1, i] = matriz[1, j];
					matriz[1, j] = aux1;

					aux2 = matriz[0, i];
					matriz[0, i] = matriz[0, j];
					matriz[0, j] = aux2;
				}
			}
		}
		ReestablecerMatriz();
		Llenar();
	}
};
}
