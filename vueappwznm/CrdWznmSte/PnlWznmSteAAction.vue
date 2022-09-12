<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="4">
		<v-card-title>
			<v-row>
				<v-col cols="4">
					<div>
						<span>{{Cpt}}</span>
					</div>
				</v-col>
				<v-col cols="8" align="end">
					&#160;
					<v-btn
						v-if="statapp.srefIxWznmVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClipboardClick()"
						:value="1"
					>
						<v-icon color="white">mdi-clipboard</v-icon>
					</v-btn>
					&#160;&#160;
					<v-btn
						v-if="statapp.srefIxWznmVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButNewClick')"
						:value="1"
					>
						<v-icon color="white">mdi-file-plus</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statapp.srefIxWznmVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButDuplicateClick')"
						:value="1"
						:disabled="!statshr.ButDuplicateActive"
					>
						<v-icon color="white">mdi-file-multiple</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statapp.srefIxWznmVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButDeleteClick')"
						:value="1"
						:disabled="!statshr.ButDeleteActive"
					>
						<v-icon color="white">mdi-file-remove</v-icon>
					</v-btn>
					&#160;&#160;
					&#160;
					<v-btn
						v-if="statapp.srefIxWznmVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="statapp.srefIxWznmVExpstate='mind'"
						:value="1"
					>
						<v-icon color="white">mdi-minus-circle</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statapp.srefIxWznmVExpstate=='mind'"
						fab
						small
						light
						color="primary"
						v-on:click="statapp.srefIxWznmVExpstate='regd'"
						:value="1"
					>
						<v-icon color="white">mdi-plus-circle</v-icon>
					</v-btn>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text
			v-if="statapp.srefIxWznmVExpstate=='regd'"
		>
			<v-data-table
				:headers="headers"
				:items="contapp.rows"
				:items-per-page="10"
				item-key="jnum"
				single-select
				show-select
				class="elevation-1 my-3"
				v-on:item-selected="handleSelect"
			/>

			<v-row>
				<v-col align="end">
					<v-tooltip left>
						<template v-slot:activator="{on,attrs}">
							<v-btn
								fab
								small
								light
								v-bind="attrs"
								v-on="on"
								:color="fiFCsiQst.sref == 'ong' ? 'orange' : fiFCsiQst.sref == 'red' ? 'red' : fiFCsiQst.sref == 'yel' ? 'yellow' : fiFCsiQst.sref == 'grn' ? 'green' : 'primary'"
								v-on:click="handleButClick('ButRefreshClick')"
							>
								<v-icon color="white">mdi-refresh</v-icon>
							</v-btn>
						</template>
						{{fiFCsiQst.tit1}}
					</v-tooltip>
				</v-col>
			</v-row>
		</v-card-text>
	</v-card>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmSteAAction',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmSteAAction.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWznmInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit('request', {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			handleButClick: function(ctlsref) {
				const dpchapp = {
					"DpchAppWznmSteAActionDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handleButClipboardClick: function() {
				/*
				*/
				Wznm.copyToClipboard(document, this.continf, this.rst, this.statshrqry, this.tag,
							["Sct","","Typ","","Trj","Vec","Vit","Snx","Seq","Tr1","Ip1","Tr2","Ip2","Tr3","Ip3","Tr4","Ip4"],
							["sct","sct2","typ","typ2","trj","vec","vit","snx","seq","tr1","ip1","tr2","ip2","tr3","ip3","tr4","ip4"]);
				/*
				*/
			},

			handleSelect: function(obj) {
				var stgiacqry = this.stgiacqry;

				if (!obj.value) stgiacqry.jnum = 0;
				else stgiacqry.jnum = obj.item.jnum;

				const dpchapp = {
					"DpchAppWznmSteAActionData": {
						"scrJref": this.scrJref,
						"StgIacQryWznmSteAAction": stgiacqry
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmSteAAction"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmSteAActionData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmSteAActionData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContInfWznmSteAAction) this.continf = dpcheng.ContInfWznmSteAAction;
				if (dpcheng.FeedFCsiQst) this.feedFCsiQst = dpcheng.FeedFCsiQst;
				if (dpcheng.StatAppWznmSteAAction) this.statapp = dpcheng.StatAppWznmSteAAction;
				if (dpcheng.StatShrWznmSteAAction) this.statshr = dpcheng.StatShrWznmSteAAction;
				if (dpcheng.StgIacWznmSteAAction) this.stgiac = dpcheng.StgIacWznmSteAAction;
				if (dpcheng.TagWznmSteAAction) {
					Wznm.unescapeBlock(dpcheng.TagWznmSteAAction);
					this.tag = dpcheng.TagWznmSteAAction;
				}
				if (dpcheng.ListWznmQSteAAction) this.rst = dpcheng.ListWznmQSteAAction;
				if (dpcheng.StatAppQryWznmSteAAction) this.statappqry = dpcheng.StatAppQryWznmSteAAction;
				if (dpcheng.StatShrQryWznmSteAAction) this.statshrqry = dpcheng.StatShrQryWznmSteAAction;
				if (dpcheng.StgIacQryWznmSteAAction) this.stgiacqry = dpcheng.StgIacQryWznmSteAAction;
				/*
				<!-- IP mergeDpchEngData - END -->
				*/

				if (dpcheng.TagWznmSteAAction) {
					var tcos = [];

					/*
					*/
					tcos.push({value: "jnum", text: "jnum"}, {value: "TcoSct", text: this.tag.TcoSct}, {value: "TcoTyp", text: this.tag.TcoTyp}, {value: "TcoTrj", text: this.tag.TcoTrj}, {value: "TcoVec", text: this.tag.TcoVec}, {value: "TcoVit", text: this.tag.TcoVit}, {value: "TcoSnx", text: this.tag.TcoSnx}, {value: "TcoSeq", text: this.tag.TcoSeq}, {value: "TcoTr1", text: this.tag.TcoTr1}, {value: "TcoIp1", text: this.tag.TcoIp1}, {value: "TcoTr2", text: this.tag.TcoTr2}, {value: "TcoIp2", text: this.tag.TcoIp2}, {value: "TcoTr3", text: this.tag.TcoTr3}, {value: "TcoIp3", text: this.tag.TcoIp3}, {value: "TcoTr4", text: this.tag.TcoTr4}, {value: "TcoIp4", text: this.tag.TcoIp4});
					/*
					*/

					this.contapp.tcos = tcos;
				}

				if (dpcheng.ListWznmQSteAAction) {
					var rows = [];

					for (var i = 0; i < this.rst.length; i++) {
						var rec = this.rst[i];
						/*
						*/
						rows.push({jnum: rec["jnum"], TcoSct: rec["sct"], TcoTyp: rec["typ"], TcoTrj: rec["trj"], TcoVec: rec["vec"], TcoVit: rec["vit"], TcoSnx: rec["snx"], TcoSeq: rec["seq"], TcoTr1: rec["tr1"], TcoIp1: rec["ip1"], TcoTr2: rec["tr2"], TcoIp2: rec["ip2"], TcoTr3: rec["tr3"], TcoIp3: rec["ip3"], TcoTr4: rec["tr4"], TcoIp4: rec["ip4"]})
						/*
						*/

					}

					this.contapp.rows = rows;
				}
			},

			handleReply: function(obj) {
				if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
				else if (obj.then == "handleDpchAppDataDoReply") this.handleDpchAppDataDoReply(obj.srefIxWznmVDpch, obj.dpcheng);
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleDpchAppDataDoReply: function(srefIxWznmVDpch, dpcheng) {
				if (srefIxWznmVDpch == "DpchEngWznmSteAActionData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmSteAActionData") this.mergeDpchEngData(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {
			/*
			*/
			/*
			*/
			Cpt: function() {
				if (this.statapp.srefIxWznmVExpstate == "mind") return(this.tag.Cpt + " (" + this.statshrqry.ntot + ")");
				return this.tag.Cpt;
			},
			/*
			*/

			headers: function() {
				return this.contapp.tcos.filter(x => x.value != "jnum")
			},

			fiFCsiQst: function() {
				if (this.feedFCsiQst && this.continf)
					for (var i = 0; i < this.feedFCsiQst.length; i++)
						if (this.feedFCsiQst[i].num == this.continf.numFCsiQst) return this.feedFCsiQst[i];

				return {sref: "gry", tit1: "invalid"}
			}
		},

		data: () => ({
			initdone: false,

			/*
			*/
			continf: null,

			feedFCsiQst: null,

			statapp: null,

			statshr: null,

			stgiac: null,

			tag: null,

			rst: null,

			statappqry: null,

			statshrqry: null,

			stgiacqry: null,

			contapp: {
				tcos: [],
				rows: [],

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
